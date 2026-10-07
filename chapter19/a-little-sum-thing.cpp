#include<iostream>
#include<numeric>
#include<vector>

#include <type_traits>
#include <cstdint>

int main(){
    std::vector<int> v{-2,-3};
    std::cout<<std::accumulate(v.cbegin(),v.cend(),v.size())<<std::endl;

    static_assert(std::is_same_v<decltype(v.size()), std::size_t>);
    static_assert(std::is_same_v<std::size_t, unsigned long>);   // 環境によって通る/通らない
    static_assert(std::is_same_v<std::size_t, std::uint64_t>);   // 同上


}
