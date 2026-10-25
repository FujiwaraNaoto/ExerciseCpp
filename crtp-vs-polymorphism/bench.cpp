#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// ---------------- 動的多態 (virtual) ----------------
struct Shape {
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

struct VCircle : Shape {
    double r;
    explicit VCircle(double r) : r(r) {}
    double area() const override { return 3.14159265358979 * r * r; }
};

struct VRect : Shape {
    double w, h;
    VRect(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
};

// ---------------- 静的多態 (CRTP) ----------------
template <class Derived>
struct ShapeBase {
    double area() const { return static_cast<const Derived&>(*this).area_impl(); }
};

struct CCircle : ShapeBase<CCircle> {
    double r;
    explicit CCircle(double r) : r(r) {}
    double area_impl() const { return 3.14159265358979 * r * r; }
};

struct CRect : ShapeBase<CRect> {
    double w, h;
    CRect(double w, double h) : w(w), h(h) {}
    double area_impl() const { return w * h; }
};

// ---------------- 集計関数 ----------------
// noinline にして、呼び出し元から型情報が伝播して脱仮想化されるのを防ぐ
__attribute__((noinline)) double sum_virtual(const std::vector<std::unique_ptr<Shape>>& v) {
    double s = 0;
    for (const auto& p : v) s += p->area();
    return s;
}

__attribute__((noinline)) double sum_virtual_ptr(const std::vector<const Shape*>& v) {
    double s = 0;
    for (const Shape* p : v) s += p->area();
    return s;
}

template <class D>
__attribute__((noinline)) double sum_crtp(const std::vector<D>& v) {
    double s = 0;
    for (const ShapeBase<D>& x : v) s += x.area();
    return s;
}

// ---------------- 計測ユーティリティ ----------------
template <class F>
double measure_ms(F f, int reps) {
    volatile double sink = 0;  // 結果を使って最適化で消されないようにする
    std::vector<double> times;
    for (int i = 0; i < reps; ++i) {
        auto t0 = std::chrono::steady_clock::now();
        sink = sink + f();
        auto t1 = std::chrono::steady_clock::now();
        times.push_back(std::chrono::duration<double, std::milli>(t1 - t0).count());
    }
    std::sort(times.begin(), times.end());
    return times[times.size() / 2];  // 中央値
}

void report(const std::string& name, double ms, double base) {
    // 日本語ラベルだと桁揃えがずれるので、数値を先に出す
    std::cout << "  " << ms << " ms  (x" << ms / base << ")  " << name << "\n";
}

int main(int argc, char** argv) {
    const std::size_t N = argc > 1 ? std::strtoul(argv[1], nullptr, 10) : 1'000'000;
    const int reps = argc > 2 ? std::atoi(argv[2]) : 50;

    std::mt19937 rng(42);
    std::uniform_real_distribution<double> dist(0.5, 2.0);
    std::cout.precision(3);
    std::cout << std::fixed << "N = " << N << ", reps = " << reps << " (median)\n";

    // ===== ケース1: 単一の型だけを大量に処理 =====
    {
        std::vector<CCircle> crtp;
        std::vector<VCircle> vflat;  // 連続メモリに置いた virtual オブジェクト
        std::vector<std::unique_ptr<Shape>> vheap;
        for (std::size_t i = 0; i < N; ++i) {
            double r = dist(rng);
            crtp.emplace_back(r);
            vflat.emplace_back(r);
            vheap.push_back(std::make_unique<VCircle>(r));
        }
        std::vector<const Shape*> vflat_ptr;
        for (auto& c : vflat) vflat_ptr.push_back(&c);

        std::cout << "\n[1] 単一型 (Circle のみ)\n";
        double b = measure_ms([&] { return sum_crtp(crtp); }, reps);
        report("CRTP           vector<CCircle>", b, b);
        report("virtual        Shape* -> 連続配置", measure_ms([&] { return sum_virtual_ptr(vflat_ptr); }, reps), b);
        report("virtual        vector<unique_ptr<Shape>>", measure_ms([&] { return sum_virtual(vheap); }, reps), b);
    }

    // ===== ケース2: 2種類の型が混在 =====
    {
        std::vector<CCircle> c_circles;
        std::vector<CRect> c_rects;
        std::vector<std::unique_ptr<Shape>> vmixed;
        for (std::size_t i = 0; i < N; ++i) {
            if (rng() % 2) {
                double r = dist(rng);
                c_circles.emplace_back(r);
                vmixed.push_back(std::make_unique<VCircle>(r));
            } else {
                double w = dist(rng), h = dist(rng);
                c_rects.emplace_back(w, h);
                vmixed.push_back(std::make_unique<VRect>(w, h));
            }
        }
        // 型ごとに並べ替えた版 (分岐予測が当たりやすくなる)
        std::vector<const Shape*> vsorted;
        for (auto& p : vmixed) vsorted.push_back(p.get());
        std::stable_partition(vsorted.begin(), vsorted.end(),
                              [](const Shape* p) { return dynamic_cast<const VCircle*>(p) != nullptr; });

        std::cout << "\n[2] 混在 (Circle / Rect がランダム順)\n";
        double b = measure_ms([&] { return sum_crtp(c_circles) + sum_crtp(c_rects); }, reps);
        report("CRTP           型ごとの vector x2", b, b);
        report("virtual        unique_ptr ランダム順", measure_ms([&] { return sum_virtual(vmixed); }, reps), b);
        report("virtual        Shape* 型ごとにソート", measure_ms([&] { return sum_virtual_ptr(vsorted); }, reps), b);
    }
}
