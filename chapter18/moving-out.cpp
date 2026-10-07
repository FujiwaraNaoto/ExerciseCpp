#include <iostream>
#include <string>


int main(){
    std::string hello{"Hello, world!"};
    std::string other(std::move(hello));
    std::cout << "hello: " << hello << ", other: " << other << std::endl;
    std::cout<< "hello.size(): " << hello.size() << ", other.size(): " << other.size() << std::endl;
}
