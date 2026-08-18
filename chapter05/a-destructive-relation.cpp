#include <iostream>
#include <memory>

struct Widget{
    virtual void draw(){std::cout<<"Widget draw()"<<std::endl;}
    virtual ~Widget(){std::cout<<"Widget destructor"<<std::endl;}
};

struct Button: public Widget{
    void draw() override{std::cout<<"Button draw()"<<std::endl;}
    ~Button(){std::cout<<"Button destructor"<<std::endl;}
};

int main(){
    std::unique_ptr<Widget> w = std::make_unique<Button>();
    w->draw();
    return 0;
}
