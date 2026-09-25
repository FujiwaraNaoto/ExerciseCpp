#include<initializer_list>
#include<iostream>

struct Container
{
    Container(int,int)
    {
        std::cout<<"Two ints\n";
    }

    Container(std::initializer_list<float> )
    {
        std::cout<<"std::initializer_list<float>\n";
    }
};

int main()
{
    Container c1(1,2);
    Container c2{1,2};

    // おまけ
    int a=1,b=2;
    Container c3{a,b};
    return 0;
}
