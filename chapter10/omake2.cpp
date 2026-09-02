#include <iostream>
#include <string>

std::string& getName(){
    static std::string name = "Alice";
    return name;
}

int main(){
    std::string name{"Bob"};
    std::cout<<"Before assignment: " << getName() << std::endl;
    getName() = name;
    std::cout<<"After assignment: " << getName() << std::endl;
}
