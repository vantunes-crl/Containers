#include <iostream>
#include "../random_acess_iterator.hpp"
#include "../reverse_iterator.hpp"
#include "../vector.hpp"

using namespace ft;

template <class T>
void print(vector<T> &vec)
{    
    typename vector<T>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << std::endl;
}