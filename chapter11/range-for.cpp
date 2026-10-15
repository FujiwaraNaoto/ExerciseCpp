#include<iostream>
#include <vector>

struct MemoryArea
{
    MemoryArea(int number): number_(number) {}
    int number_;
};

class MemoryAreaContainer
{
public:
    MemoryAreaContainer(){};
    MemoryAreaContainer(const std::vector<MemoryArea>& areas): memoryAreas_(areas) {}

    std::vector<MemoryArea>& getMemoryAreas()
    {
        return memoryAreas_;
    }

private:
    std::vector<MemoryArea> memoryAreas_{MemoryArea{1}, MemoryArea{2}, MemoryArea{3}};
};

int main(){

    for(const auto &area: MemoryAreaContainer().getMemoryAreas()){
        std::cout << "Memory area number: " << area.number_ << std::endl;
    }
}
