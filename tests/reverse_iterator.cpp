#include "print.hpp"
#include <vector>

using namespace ft;

int main()
{
    vector<int>::reverse_iterator it;
    vector<int>::reverse_iterator it2;
    vector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    it = vec.rbegin();

    ++it;
    std::cout << *it << " after ++*\n";
    std::cout << *it++ << " after *++\n";
    --it;
    std::cout << *it << " after --*\n";
    std::cout << *it-- << " after *--\n";
    it = it;
    it += 2;
    std::cout << *it << " after += 2\n";
    it -= 2;
    std::cout << *it << " after -= 2\n";

    it2 = vec.rend();
    std::cout << (it < it2) << " operator < \n";
    std::cout << (it > it2) << " operator > \n";
    std::cout << (it >= it2) << " operator >= \n";
    std::cout << (it <= it2) << " operator <= \n";

    std::cout << it[9] << " operator []\n";

}