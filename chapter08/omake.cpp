#include <iostream>
#include <string>


int main(){
    const std::string& hoge="Hello";//Helloはprvalueで、hogeはconst lvalue referenceで受け取るので、Helloの寿命が延長される
    std::cout<<hoge<<std::endl;

    std::string fuga="Hello";//Helloはprvalueで、fugaはlvalueなので、Helloの寿命は延長されない
    std::cout<<fuga<<std::endl;

}
