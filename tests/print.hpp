#include <iostream>
#include "../vector.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>

#define TYPE int
#ifndef NAMESPACE
#define NAMESPACE ft
#endif


template <class T>
std::string print(ft::vector<T> &vec)
{    
    typename ft::vector<T>::iterator it;
    
    std::stringstream ss;
    std::streambuf * old_buf = std::cout.rdbuf(ss.rdbuf());

    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it;

    std::cout.rdbuf(old_buf);
    return ss.str();
}

template <class T>
std::string print(std::vector<T> &vec)
{    
    typename std::vector<T>::iterator it;
    std::stringstream ss;
    std::streambuf * old_buf = std::cout.rdbuf(ss.rdbuf());

    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it;

    std::cout.rdbuf(old_buf);
    return ss.str();
}