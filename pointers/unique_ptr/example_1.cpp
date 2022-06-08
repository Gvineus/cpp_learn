// Exmaple source 
// https://www.learncpp.com/cpp-tutorial/stdunique_ptr/


#include <iostream>
#include <memory>


class Resource{

public:
    Resource( ) { std::cout << "Resource acquired" << std::endl;}
    ~Resource( ) { std::cout << "Resource destroyed" << std::endl;}
};

int main(){
    std::unique_ptr<Resource> res{ new Resource()};

    return 0;
}