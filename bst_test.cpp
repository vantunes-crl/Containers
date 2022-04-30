#include <iostream>
#include "binary_tree.hpp"
#include "utility/pair.hpp"
#include <map>

using namespace ft;

int main()
{

    // std::map<int, char> map;
    // std::map<int, char>::iterator it;
    // std::map<int, char>::iterator it2;

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

    // it = map.begin();
    // it2 = map.end();

    // int i = 0;
    // while (++i < 10)
    // {
    //     std::cout << it->first << std::endl;
    //     ++it;
    // }
    // i = 0;
    // while (++i < 10)
    // {
    //     std::cout << it->first << std::endl;
    //     ++it;
    // } 
    // std::cout << (*it < *it2) << std::endl;

    // for (auto i = map.begin();i != map.end(); ++i)
    //     std::cout << i->first << i->second << std::endl;


    std::cout << "my binary tree---------------------\n\n";
    binary_tree<pair<int, char>> bi;
    iterator_tree<pair<int, char>> it;

    //bst_iterator<ft::pair<int, char>> it;

    bi.insert(ft::make_pair(15, 'a'));
    bi.insert(ft::make_pair(10, 'a'));
    bi.insert(ft::make_pair(8, 'a'));
    bi.insert(ft::make_pair(12, 'a'));
    bi.insert(ft::make_pair(18, 'a'));
    bi.insert(ft::make_pair(20, 'a'));
    bi.insert(ft::make_pair(17, 'a'));
    bi.insert(ft::make_pair(6, 'a'));
    bi.insert(ft::make_pair(9, 'a'));
    bi.insert(ft::make_pair(11, 'a'));
    bi.insert(ft::make_pair(13, 'a'));
    bi.insert(ft::make_pair(16, 'a'));
    bi.insert(ft::make_pair(19, 'a'));
    bi.insert(ft::make_pair(22, 'a'));

    it = bi.getRoot();

    ++it;
    std::cout << it->first << std::endl;

   
}