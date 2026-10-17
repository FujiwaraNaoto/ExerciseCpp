#include<iostream>
#include<string>
using namespace std;


template<class T> // (a) same old base template as before 
void f( T ){
    cout<<"template<class T> void f(T)"<<endl;
}

template<>        // (c) explicit specialization, this time of (a)
void f<>(int*){
    cout<<"template<> void f<>(int*)"<<endl;
}

template<class T> // (b) a second base template, overloads (a) 
void f( T* ){
    cout<<"template<class T> void f<>(T*)"<<endl;
}


int main(){
    int a=2;
    int *p =&a;
    f(p);
    
}
