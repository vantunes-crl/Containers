#include "../print.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    vec.at(5) = 10;

    std::cout << vec.at(5) << std::endl;
    print(vec);
}