#include <iostream>
#include <type_traits>

int main()
{
    char char1 = 1;
    char char2 = 2;
    std::cout<<std::is_same_v<decltype(char1 + char2), char>;
}
