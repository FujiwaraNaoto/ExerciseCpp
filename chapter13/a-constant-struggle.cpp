#include<iostream>
#include<type_traits>

template<typename T>
void byValue(T value) {
    std::cout << std::is_const_v<T>;
}

template<typename T>
void byReference(T& value) {
    std::cout << std::is_const_v<T>;
}

int main()
{
    int nonConstInt=0;
    const int constInt=0;
    byValue(nonConstInt);
    byValue(constInt);
    byReference(nonConstInt);
    byReference(constInt);
}
