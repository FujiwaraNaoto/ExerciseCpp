#include <iostream>

struct Member
{
};

struct WillItMove
{
    WillItMove()=default;
    WillItMove(WillItMove&&) = default;
    const Member constMember_{};
};

int main(){
    WillItMove objectWithConstMember;
    WillItMove moved{std::move(objectWithConstMember)};
    std::cout<<"It moved!"<<std::endl;

    std::is_move_assignable_v<WillItMove> ? std::cout<<"Yes, it is move assignable!"<<std::endl : std::cout<<"No, it is not move assignable!"<<std::endl;
}

