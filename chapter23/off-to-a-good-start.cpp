#include <iostream>

struct Logger{};
struct Configuration{};

Logger initializeLogger()
{
    std::cout<<"Initializeing logger"<<std::endl;
    return Logger{};
}

Configuration readConfiguration()
{
    std::cout<<"Reading configuration"<<std::endl;
    return Configuration{};
}

void startProgram(Logger logger,Configuration configuration){
    std::cout<<"Starting Program"<<std::endl;
}

int main(){
    startProgram(initializeLogger(),readConfiguration());
}
