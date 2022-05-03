#include <iostream>
#include "binary_tree.hpp"
#include "utility/pair.hpp"
#include <map>
#include "map.hpp"

using namespace ft;

int main()
{

    // std::map<int, char> map;

    // map.insert(make_pair(15, 'a'));
    // map.insert(make_pair(10, 'b'));
    // map.insert(make_pair(20, 'c'));
    // map.insert(make_pair(18, 'd'));
    // map.insert(make_pair(30, 'd'));
    // map.insert(make_pair(12, 'd'));
    // map.insert(make_pair(25, 'd'));
    // map.insert(make_pair(8, 'd'));
    // map.insert(make_pair(16, 'd'));
    // map.insert(make_pair(19, 'd'));

    // auto i = map.begin();
    // i++;
    // i++;

    // std::cout << i->first << std::endl;
    // for (auto i = map.begin();i != map.end(); ++i)
    //     std::cout << i->first << i->second << std::endl;


    //std::cout << "my binary tree---------------------\n\n";
    ft::map<int, char> bi;

    bi.insert(ft::make_pair(15, 'a'));
    bi.insert(ft::make_pair(10, 'b'));
    bi.insert(ft::make_pair(20, 'c'));
    bi.insert(ft::make_pair(18, 'd'));

    bi.insert(ft::make_pair(30, 'd'));
    bi.insert(ft::make_pair(12, 'd'));
    bi.insert(ft::make_pair(25, 'd'));
    bi.insert(ft::make_pair(8, 'd'));
    bi.insert(ft::make_pair(16, 'd'));
    //auto p =  bi.insert(ft::make_pair(19, 'd'));
    
    // std::cout << p.first->first << p.second << std::endl;
    
    ft::map<int, char>::iterator it;

    for (auto it = bi.begin(); it != bi.end(); ++it)
        std::cout << it->first << it->second << std::endl;

    // for (auto i = 0; i != bi.Size(); ++i)
    // {
    //     std::cout << it->first << it->second << std::endl;    
    //     ++it;
    // }
    
    // //bi.remove(ft::make_pair(25,'d'));
    // auto i = bi.begin();
    // std::cout << i->first << i->second<< std::endl;
    

    //bi.inorder(bi.getRoot());
    //std::cout << bi.getRoot()->data.first << bi.getRoot()->data.second;
}