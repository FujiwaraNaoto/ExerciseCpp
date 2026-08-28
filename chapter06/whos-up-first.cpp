#include<iostream>

struct Resource{
    Resource(){
        std::cout << "Resource constructor" << std::endl;
    }
};

struct Consumer{
    Consumer(const Resource& resource_){
        std::cout << "Consumer constructor" << std::endl;
    }
};

struct Job{
    Job():resource_{}, consumer_{resource_}{}
    Consumer consumer_;
    Resource resource_;
};

int main(){
    Job job;
    return 0;
}
