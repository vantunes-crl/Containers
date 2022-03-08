#include "vector.hpp"
#include <vector>
#include "iterator.hpp"

int main()
{
    {
        // std::cout << "----------------------------- my vec------------------------------------\n";
        // ft::vector<int> vec;

        // vec.push_back(7);
        // vec.push_back(8);
        // vec.push_back(8);
        // vec.pop_back();
        // vec.pop_back();

        // for (int i = 0; i < 4; ++i)
        //     std::cout << vec[i] << std::endl;
        
        // //vec.reserve(5);
        // vec.resize(9);
        // std::cout << vec.size() << " size \n";
        // std::cout << vec.capacity() << std::endl;
    }
    {
        std::cout << "-----------------------------vec------------------------------------\n";
        std::vector<int> vec;
        std::vector<int>::const_iterator it;
        
        vec.push_back(7);
        vec.push_back(8);
        vec.push_back(8);
        // vec.pop_back();
        // vec.pop_back();

        //it = it + 1;
        // for (int i = 0; i < 4; ++i)
        //     std::cout << vec[i] << std::endl;
        //vec.resize(5);
        
        for(it = vec.begin(); it != vec.end(); it++)
        {
            std::cout << *it << " ";
        }
        it == it;
        it += 5;
        it--;
        it[5];
        *it;
        it < it;
        //vec.reserve(5);
        // std::cout <<  vec.size() << " size \n";
        // std::cout << vec.capacity() << std::endl;
    }
}