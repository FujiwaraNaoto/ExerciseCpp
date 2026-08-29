#include <iostream>
#include <string>

std::string getName(){
    return "Alice";
}
void username(const std::string& name){
    std::cout << " const std::string& name, Username: " << name << std::endl;
}

void username(std::string&& name){
    std::cout << "std::string&& name, Username: " << name << std::endl;
}

int main(){

    const std::string& hello = "Hello";// prvalue　をconst lvalue referenceにバインドすることはできる
    std::cout<<hello<<std::endl;
    
    username("Bob");
    username(std::string("Charlie"));
    username(getName());
}
