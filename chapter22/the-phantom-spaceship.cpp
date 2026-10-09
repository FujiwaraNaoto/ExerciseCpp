#include<iostream>
#include<string>
using namespace std;

struct GameObject
{
    GameObject(){
        std::cout<<"Created a " <<getType()<<std::endl;
    }   
    void render() const{
        std::cout<<"Rendered a "<<getType()<<std::endl;
    }
    virtual std::string getType() const {return "GameObject";}
};

class Spaceship: public GameObject
{
    std::string getType() const override{return "Spaceship";}
};

void display(const GameObject &gameObject){
    gameObject.render();
}

int main(){
    GameObject gameObject;
    Spaceship spaceship;
    display(gameObject);
    display(spaceship);
}
