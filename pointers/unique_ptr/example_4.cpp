#include <iostream>
#include <memory>
#include <utility>

class Resource{

public:
    Resource( ) { std::cout << "Resource acquired" << std::endl;}
    ~Resource( ) { std::cout << "Resource destroyed" << std::endl;}

    friend std::ostream& operator<< ( std::ostream& out, const Resource &res){
        out << "I am a resource";
        return out;
    }
};

void takeOwnerShip(std::unique_ptr<Resource> res){
    if(static_cast<bool> (res) == true){
        std::cout << *res << '\n';
    }
}

void useResource(Resource* res)
{
	if (res)
		std::cout << *res << '\n';
}

int main()
{
    std::unique_ptr<Resource> res{std::make_unique<Resource>()};

    useResource(res.get());
    //takeOwnerShip(std::move(res));

    std::cout<< "Ending program" << std::endl;

    return 0;
}