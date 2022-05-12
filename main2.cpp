#include "map.hpp"
#include <iostream>

using namespace ft;
 
int main()
{
 
    // initialize container
    map<int, int> mp;
 
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 10 });
    mp.insert({ 5, 50 });
    mp.insert({ 4, 40 });
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        std::cout << (*it).first << " " <<
                              (*it).second << std::endl;
    }
 
    // when 2 is present
    auto it = mp.lower_bound(2);
    std::cout << "The lower bound of key 2 is ";
    std::cout << (*it).first << " " << (*it).second << std::endl;
 
    // when 3 is not present
    // points to next greater after 3
    it = mp.lower_bound(3);
    std::cout << "The lower bound of key 3 is ";
    std::cout << (*it).first << " " << (*it).second;
 
    // when 6 exceeds
    it = mp.lower_bound(6);
    std::cout << "\nThe lower bound of key 6 is ";
    std::cout << (*it).first << " " << (*it).second << std::endl;
    return 0;
}