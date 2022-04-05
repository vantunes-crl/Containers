// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout
#include "vector.hpp"
#include "tests/print.hpp"
#include <stdlib.h>

int main ()
{
    ft::vector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    print(vec);

}