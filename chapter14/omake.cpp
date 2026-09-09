#include<iostream>
#include<cctype>

char to_reverse(char c){
    return c^('a'^'A');
}




int main(){
    
    std::string str="Hello World!";
    for(char c : str){
        std::cout<<to_reverse(c);
    }
    std::cout<<std::endl;


    for(char c : str){
        std::cout<<static_cast<char>(std::toupper(c));
    }
    std::cout<<std::endl;


     for(char c : str){
        std::cout<<static_cast<char>(std::tolower(c));
    }
    std::cout<<std::endl;

}
