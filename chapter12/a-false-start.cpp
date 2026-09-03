#include<iostream>
#include<stdexcept>


struct Engine
{
    ~Engine() {
        std::cout << "Engine destroyed" << std::endl;
    }
};

struct Machine
{
    Machine() {
        throw std::runtime_error("Failed to construct Machine");
    }

    ~Machine() {
        std::cout << "Machine destroyed" << std::endl;
    }
    Engine engine_;
};


int main(){
    try{
        Machine machine;
    } catch (const std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
}
