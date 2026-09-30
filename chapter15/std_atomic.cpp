#include <iostream>
#include <atomic>

template <typename T>
void print_lock_free(){
    std::atomic<T> a;
    std::cout<< "Type: " << typeid(T).name() << std::endl;
    std::cout<< "a.is_always_lock_free=" << a.is_always_lock_free << std::endl;
    std::cout<< "a.is_lock_free()=" << a.is_lock_free() << std::endl;
}

template <typename... Ts>
void print_lock_free_all(){
    (print_lock_free<Ts>(), ...);
}

int main(){

    std::atomic<int> counter;
    std::cout<< "counter.is_always_lock_free = " << counter.is_always_lock_free << std::endl;
    std::cout<< "counter.is_lock_free()=" << counter.is_lock_free() << std::endl;


    print_lock_free_all<char, short, int, long, long long>();

}
