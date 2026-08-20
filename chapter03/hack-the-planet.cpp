#include<iostream>

int getUserId(){
    return 1337;
}

void restrictedTask1()
{
    int id=getUserId();
    if(id==1337)
    {
        std::cout<<"did task1\n";
    }
}

void restrictedTask2()
{
    int id;
    if(id==1337)
    {
        std::cout<<"did task2\n";
    }
}

int main(){
    restrictedTask1();
    restrictedTask2();
}
