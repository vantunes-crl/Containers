#include "../print.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec1(10,3);
    NAMESPACE::vector<TYPE> vec2; //default
    
    for (int i = 0; i < 10; ++i)
        vec2.push_back(i);
    

    NAMESPACE::vector<TYPE> vec3(vec2.begin(), vec2.end());

    std::cout << vec3.capacity() << " Capacity\n";
    print(vec2);
    std::cout << "---vector (10, 3)---\n";
    print(vec1);
    
}