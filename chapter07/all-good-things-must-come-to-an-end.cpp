#include <iostream>
#include <string>


struct Connection
{
    Connection(const std::string& name)
        : name_(name)
    {
        std::cout << "Connection " << name_ << " established." << std::endl;
    }

    ~Connection()
    {
        std::cout << "Destroyed " << name_ << " closed." << std::endl;
    }

    std::string name_;
};

Connection global{"Global"};

Connection &get()
{
    static Connection local{"Local static"};
    return local;
}

int main(){
    Connection local{"Local"};
    Connection &tmp1 = get();
    Connection &tmp2 = get();
}
