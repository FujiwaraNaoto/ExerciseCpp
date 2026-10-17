#include<iostream>
#include<string>
using namespace std;


template<class T> // (a)
void f( T ){
    cout<<"template<class T> void f(T)"<<endl;
}


template<class T> // (b)
void f( T* ){
    cout<<"template<class T> void f<>(T*)"<<endl;
}

template<>        // (c) explicit specialization, this time of (b)
void f<>(int*){
    cout<<"template<> void f<>(int*)"<<endl;
}



int main(){
    int a=2;
    int *p =&a;
    f(p);
    
}
