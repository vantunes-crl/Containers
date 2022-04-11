#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int>::iterator it;
    NAMESPACE::vector<int>::iterator it2;
    NAMESPACE::vector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    it = vec.begin();

    ++it;
    std::cout << *it << " after ++*\n";
    std::cout << *it++ << " after *++\n";
    std::cout << *it++ << " after *++\n";
    --it;
    std::cout << *it << " after --*\n";
    std::cout << *it-- << " after *--\n";
    it = it;
    it += 2;
    std::cout << *it << " after += 2\n";
    it -= 2;
    std::cout << *it << " after -= 2\n";

    it2 = vec.end();
    std::cout << (it < it2) << " operator < \n";
    std::cout << (it > it2) << " operator > \n";
    std::cout << (it >= it2) << " operator >= \n";
    std::cout << (it <= it2) << " operator <= \n";

    std::cout << it[4] << " operator []\n";

    
}