#include "../print.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    std::cout << *vec.erase(vec.begin(), vec.end()) << " pos return " << std::endl;

    print(vec);
}