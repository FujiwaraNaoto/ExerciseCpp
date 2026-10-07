#include<cctype>
#include<string>
#include<iostream>
#include<cstddef>
#include<iomanip>
#include<utility>


using namespace std;

bool is_sso(const std::string& s){
    auto base = reinterpret_cast<const char*>(&s);
    return s.data() >= base and s.data() < base + sizeof(s);
}

void dump(const char* label, const std::string& s){
    auto bytes = reinterpret_cast<const unsigned char*>(&s);

    std::cout<<"label"<<label<<std::endl;
    std::cout<< "size="<<s.size()
             << " capacity="<<s.capacity()
             << " sso="<<std::boolalpha << is_sso(s) <<"\n"
             << "this="<<static_cast<const void*>(&s)
             << " data="<<static_cast<const void*>(s.data())<<"\n";


    std::cout<<"hex:";
    for(int i=0;i<sizeof(s);i++){
        if(i%8==0) std::cout<<' ';
        std::cout<<(std::isprint(bytes[i])?static_cast<char>(bytes[i]):'.')<<" ";
    }
    std::cout<<"\n\n";


    std::cout<<"char:";
    for(int i=0;i<sizeof(s);i++){
        if(i%8==0) std::cout<<' ';
        std::cout<<(std::isprint(bytes[i])?static_cast<char>(bytes[i]):'.')<<" ";
    }
    std::cout<<"\n\n";

    std::cout<<"bin:";
    for(int i=0;i<sizeof(s);i++){
        if(i%8==0) std::cout<<' ';
        std::cout << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(bytes[i]) << ' ';
    }

    std::cout<<"\n\n";




}


int main(){
    std::cout<<"sizeof(std::string) = "<<sizeof(std::string) <<"\n\n";

    //SSOにおさまる長さ
    std::string hello{"Hello, world!"};
    dump("hello (before move)",hello);
    std::string other(std::move(hello));
    dump("hello (after move)",hello);
    dump("other",other);


    //SSOにおさまらない長さ
    std::string longstr{"This string is definitely longer than SSO capacity"};
    dump("longstr (before move)",longstr);
    std::string other2(std::move(longstr));
    dump("longstr (after move)",longstr);
    dump("other2",other2);


}

