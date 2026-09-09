#include<cstdio>
#include<typeinfo>
#include<iostream>
#include<type_traits>

template <class Type>
void PrintType(Type v)
{
    printf("Type = %s\n", typeid(v).name());
}
int func(int x) { return x; }

int main()
{
    int a = 0;
    const int& b = a;
    int c[4];
    PrintType(a);//Type = int
    PrintType(b);//Type = int
    PrintType(c);//Type = int * __ptr64
    PrintType(func);//Type = int (__cdecl*)(int)

    int sample=5;
    int& ref=sample;
    int v=std::decay_t<decltype(ref)>(ref);
    std::cout<<v<<std::endl;
    return 0;
}
