#include <iostream>

struct MemoryArea
{
    MemoryArea(int number): number_(number) {}
    ~MemoryArea() { std::cout << "Free memory area " << number_ << std::endl; }
    int number_;
};

MemoryArea getMemoryArea(int number)
{
    return MemoryArea{number};
}

struct DataSource
{
    DataSource(const MemoryArea& area): memoryArea_(area) {}
    const MemoryArea& memoryArea_;
};

int main()
{
    const auto &referece1 = getMemoryArea(1);
    std::cout<< "Bound reference 1" << std::endl;
    const auto &referece2 = getMemoryArea(2).number_;
    std::cout<< "Bound reference 2" << std::endl;
    const auto &referece3 = DataSource(getMemoryArea(3));
    std::cout<< "Bound reference 3" << std::endl;
}
