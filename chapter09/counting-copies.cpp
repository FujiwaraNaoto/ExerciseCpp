#include<iostream>

struct Resource 
{
    Resource()=default;
    Resource(const Resource&) { std::cout << "copy\n"; }
};

Resource getResource() 
{
    return Resource{};
}

int main()
{
    Resource resource1 = getResource();
    Resource r2{resource1};
    return 0;
}

