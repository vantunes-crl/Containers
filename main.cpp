#include <iostream>
#include "binary_tree.hpp"
#include "utility/pair.hpp"
#include <map>
#include "map.hpp"

using namespace ft;

int main()
{

    // std::map<int, char> map;
    // std::map<int, char>::iterator it;

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
    // ++it;
    // ++it;
    // ++it;
    // ++it;
    // ++it;
    // --it;
    // --it;
    // --it;


    // std::cout << it->first << std::endl;
    // auto i = map.begin();
    // i++;
    // i++;

    // std::cout << i->first << std::endl;
    // for (auto i = map.begin();i != map.end(); ++i)
    //     std::cout << i->first << i->second << std::endl;


    //std::cout << "my binary tree---------------------\n\n";
    map<int, char> bi;
    map<int, char> be;
    
    bi.insert(make_pair(15, 'a'));
    bi.insert(make_pair(10, 'b'));
    bi.insert(make_pair(20, 'c'));
    bi.insert(make_pair(18, 'd'));
    bi.insert(make_pair(30, 'd'));
    bi.insert(make_pair(12, 't'));
    bi.insert(make_pair(25, 'd'));
    bi.insert(make_pair(8, 'd'));
    bi.insert(make_pair(16, 'd'));
    bi.insert(make_pair(17, 'd'));

    /* second tree */
    be.insert(make_pair(31, 'd'));
    be.insert(make_pair(90, 'd'));
    be.insert(make_pair(22, 'd'));
    be.insert(make_pair(50, 'd'));
    bi.swap(be);

    //bi = be;


    // map<int, char> map(bi.begin(), bi.end());

    // //auto p =  bi.insert(ft::make_pair(19, 'd'));
    // // std::cout << p.first->first << p.second << std::endl;

    bi.clear();
    map<int, char>::iterator it;
    //it = bi.begin();


    //bi.erase(bi.begin(), bi.end());
    // map<int, char> be;

    // be.insert(bi.begin(), bi.end());

    // for (it = be.begin(); it != be.end(); ++it)
    //     std::cout << it->first << it->second << std::endl;

    //std::cout << bi.max_size() << std::endl;

    //char c = bi[15] = 'b';
    // std::cout << c << std::endl;
    // std::cout << "size " << bi.size() << std::endl;
    //it = bi.begin();


   
    // //it->first;
   // bi.insert(it, make_pair(13,'c'));


    // //std::cout  << it->first << std::endl;

    // //std::cout << it->first << std::endl;

    //std::cout << bi.empty();
    // std::cout << bi.size() << std::endl;
    // std::cout << be.size() << std::endl;
    
    for (it = bi.begin(); it != bi.end(); ++it)
        std::cout << it->first << it->second << std::endl;

    // for (auto i = 0; i != map.Size(); ++i)
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