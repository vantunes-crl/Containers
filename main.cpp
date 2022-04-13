#include "map.hpp"
#include <iostream>
#include <map>

using namespace ft;

int main()
{
    map<const std::string, int> m;

    auto p = make_pair("ola" , 10);

    // std::cout << p.first << std::endl;
    // std::cout << p.second << std::endl;
    m.insert(p);
}