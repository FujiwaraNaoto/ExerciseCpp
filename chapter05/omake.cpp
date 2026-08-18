#include <iostream>
#include <memory>

struct Widget{
    virtual void draw(){std::cout<<"Widget draw()"<<std::endl;}
    virtual ~Widget(){std::cout<<"Widget destructor"<<std::endl;}
};

struct Button: public Widget{
    Button(){};
    Button(const Button& other){
        std::cout<<"Button copy constructor"<<std::endl;
    }
    Button& operator=(const Button& other){
        std::cout<<"Button copy assignment operator"<<std::endl;
        return *this;
    }
    
    void draw() override{std::cout<<"Button draw()"<<std::endl;}
    ~Button(){std::cout<<"Button destructor"<<std::endl;}
};

int main(){
    
    {
        std::cout<<"test1"<<std::endl;
        Button b1,b2;
        b1=std::move(b2);//Button copy assignment operator
        Button b3=std::move(b2);//Button copy constructor
    }

    
    {
        std::cout<<"test2"<<std::endl;
        Button btn;
        Widget w=btn;
        w.draw();//Widget draw() 
    }
    return 0;
}
