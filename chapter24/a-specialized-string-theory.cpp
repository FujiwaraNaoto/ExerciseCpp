#include<iostream>
#include<string>

template<typename T>
void serialize(T&){
    std::cout<<"template"<<std::endl;
} // 1

template<>
void serialize(const std::string&){
    std::cout<<"specialization"<<std::endl;
} // 2

void serialize(const std::string&){
    std::cout<<"normal function"<<std::endl;
} // 3

int main(){
    std::string hello_world{"Hello,world!"};
    serialize(hello_world); //左辺値の場合
    serialize(std::string{"Goodbye,world!"}); //右辺値の場合
}
