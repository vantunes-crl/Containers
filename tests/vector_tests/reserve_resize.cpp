#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int> vec;
    int i = -1;

    while (++i < 5)
        vec.push_back(i);
    
    vec.reserve(100);
    std::cout << vec.capacity() << std::endl;
    vec.reserve(90);
    std::cout << vec.capacity() << std::endl;

    vec.resize(20);
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;

    print(vec);
}