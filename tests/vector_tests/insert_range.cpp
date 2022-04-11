#include "../print.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec;
    NAMESPACE::vector<TYPE> vec2;

    int i = -1;

    while (++i < 10)
        vec.push_back(i);
    i = -1;
    while (++i < 10)
        vec2.push_back(i);
    
    std::cout << "----------------------------------\n";
    vec.insert(vec.begin(), vec2.begin(), vec2.end());
    print(vec);
}