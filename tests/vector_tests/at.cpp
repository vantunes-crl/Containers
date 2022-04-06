#include "../print.hpp"

int main()
{
    ft::vector<int> vec;
    std::vector<int> vec2;


    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    for (int i = 0; i < 10; ++i)
        vec2.push_back(i);
    
    vec.at(5) = 10;
    std::cout << "--------------------------------------------------------------------------------\n";
    vec2.at(5) = 10;

    std::cout << vec.at(5) << std::endl;
    print(vec);
    print(vec2);
}