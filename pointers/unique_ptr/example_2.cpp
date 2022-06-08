#include <iostream>
#include <memory>
#include <utility>

class Resource{

public:
    Resource( ) { std::cout << "Resource acquired" << std::endl;}
    ~Resource( ) { std::cout << "Resource destroyed" << std::endl;}

    std::string memory_string = "";
};

int main(){

    std::unique_ptr<Resource> res1{new Resource()};
    std::unique_ptr<Resource> res2{ };

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

    res1->memory_string = "I rememeber this text message";

    // res2 = res1; // Won't compile: copy assignment is disabled
    res2 = std::move(res1);

    std::cout << "Ownership transfered" << std::endl;

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

    std::cout << res2->memory_string << std::endl;

    return 0;
}