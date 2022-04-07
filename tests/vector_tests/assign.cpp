#include "../print.hpp"


int main()
{
    ft::vector<TYPE> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    //print(vec);
    std::cout << "--------------------\n";
    vec.assign(7, 100);
    print(vec);
    
}