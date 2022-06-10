// Exmaple source 
// https://www.learncpp.com/cpp-tutorial/stdunique_ptr/


#include <iostream>
#include <memory>


class Resource{

public:
    Resource( ) { std::cout << "Resource acquired" << std::endl;}
    ~Resource( ) { std::cout << "Resource destroyed" << std::endl;}
};

std::unique_ptr<Resource> createResource(){

    return std::make_unique<Resource>();
}

int main(){
    std::unique_ptr<Resource> res{ new Resource()};

    auto ptr{ createResource() }

    return 0;
}