#include "vector.hpp"
#include <vector>


int main()
{
    ft::vector<int> vec;


    for (int i = 0; i < 500; ++i)
    {
        vec.push_back(i);
    }

    vec.assign(20,50);

    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

}

