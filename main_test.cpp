#include "vector.hpp"
#include <vector>


int main()
{
    std::vector<int> vec;


    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    vec.erase(vec.begin() + 2);

    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

}

