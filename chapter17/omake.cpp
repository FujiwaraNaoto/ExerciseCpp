#include<iostream>

struct Points2{
    explicit Points2(int value):value_(value){}
    int value_;
};

struct Player{
    explicit Player(Points2 points):points_(points){}
    Points2 points_;
};

int main(){
    Player player(3);
    std::cout<<player.points_.value_<<std::endl;
}
