#include "../print.hpp"

int main()
{
    std::vector<TYPE> vec;
    std::vector<TYPE> vec2;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    for (int i = 0; i < 10; ++i)
        vec2.push_back(1);
    
    //print(vec);
    std::cout << "--------------------\n";
    //vec.assign(vec2.begin(), vec2.end());

    vec = vec2;
    print(vec);
    
}