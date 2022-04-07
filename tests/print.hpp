#include <iostream>
#include "../vector.hpp"
#include <vector>

#define TYPE int
#define NAMESPACE ft


template <class T>
void print(ft::vector<T> &vec)
{    
    typename ft::vector<T>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << std::endl;
}

template <class T>
void print(std::vector<T> &vec)
{    
    typename std::vector<T>::iterator it;

    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << std::endl;
}