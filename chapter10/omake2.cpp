#include <iostream>
#include <string>

struct Person{
    std::string name;
    int age;
};

Person& getName(){
    static Person person{"Alice", 30};
    return person;
}

int main(){
    Person p{"Bob", 25};
    std::cout<<"Before assignment: " << getName().name << ", " << getName().age << std::endl;
    getName() = p;
    std::cout<<"After assignment: " << getName().name << ", " << getName().age << std::endl;
}
