#include "map.hpp"
#include <map>
#include <iostream>

using namespace ft;


//  _M_lower_bound(_Link_type __x, _Base_ptr __y,
// 		   const _Key& __k)
//     {
//       while (__x != 0)
// 	if (!_M_impl._M_key_compare(_S_key(__x), __k))
// 	  __y = __x, __x = _S_left(__x);
// 	else
// 	  __x = _S_right(__x);
//       return iterator(__y);
//     }

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