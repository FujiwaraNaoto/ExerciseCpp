#include <iostream>
#include <cstdint>
using namespace std;


// 8+4+2+1+1 = 16
struct [[gnu::packed]] TrapFrame1{
    uint64_t rax; // 8byte
    uint32_t eax; // 4byte
    uint16_t ax; // 2byte
    uint8_t al; // 1byte
    uint8_t ah; // 1byte
};


struct TrapFrame2{
    uint64_t rax;
    uint8_t ah;
    uint32_t eax;
    uint8_t al;
    uint16_t ax;
};

struct [[gnu::packed]] TrapFrame3{
    uint64_t rax;
    uint8_t ah;
    uint32_t eax;
    uint8_t al;
    uint16_t ax;
};

struct TrapFrame4{
    uint64_t rax;
    uint8_t ah;
    uint32_t eax;
    uint8_t al;
    uint16_t ax;
}__attribute__((__packed__));//古い書き方



int main(){
    cout<<"sizeof(TrapFrame1)="<<sizeof(TrapFrame1)<<endl;
    cout<<"sizeof(TrapFrame2)="<<sizeof(TrapFrame2)<<endl;
    cout<<"sizeof(TrapFrame3)="<<sizeof(TrapFrame3)<<endl;
    cout<<"sizeof(TrapFrame4)="<<sizeof(TrapFrame4)<<endl;
}
