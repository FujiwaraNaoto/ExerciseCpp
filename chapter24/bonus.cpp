#include<iostream>
#include<string>


void serialize(const std::string&){
    std::cout<<"normal function"<<std::endl;
} // 3

template<typename T>
void serialize(const T&){
    std::cout<<"const template"<<std::endl;
} 

int main(){
    std::string hello_world{"Hello,world!"};
    serialize(hello_world); //左辺値の場合
    serialize(std::string{"Goodbye,world!"}); //右辺値の場合
}
