#include "vector.hpp"
#include <vector>
#include "reverse_iterator.hpp"
#include "random_acess_iterator.hpp"

using namespace ft;

int main()
{
    vector<int>::iterator it;

    vector<int> vec;

    for (int i = 0; i < 9; ++i)
        vec.push_back(10);
    
    std::cout << vec.size();
    
    // std::cout << *vec.begin() << std::endl;
    // std::cout << *vec.end() << std::endl;

    // for (it = vec.begin(); it != vec.end(); ++it)
    //     std::cout << *it << std::endl;
    it = vec.begin();
    *it = 20;
    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << std::endl;
}