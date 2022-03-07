#include "vector.hpp"
#include <vector>

int main()
{
    {
        std::cout << "----------------------------- my vec------------------------------------\n";
        ft::vector<int> vec;

        vec.push_back(7);
        vec.push_back(8);
        vec.push_back(8);
        vec.pop_back();
        vec.pop_back();

        for (int i = 0; i < 4; ++i)
            std::cout << vec[i] << std::endl;
        
        //vec.reserve(5);
        std::cout << vec.size() << " size \n";
        std::cout << vec.capacity() << std::endl;
    }
    {
        std::cout << "-----------------------------vec------------------------------------\n";
        std::vector<int> vec;

        vec.push_back(7);
        vec.push_back(8);
        vec.push_back(8);
        vec.pop_back();
        vec.pop_back();

        for (int i = 0; i < 4; ++i)
            std::cout << vec[i] << std::endl;
        
        //vec.reserve(5);
        std::cout << vec.size() << " size \n";
        std::cout << vec.capacity() << std::endl;
    }
}