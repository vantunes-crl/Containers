#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int>::reverse_iterator it;
    NAMESPACE::vector<int>::reverse_iterator it2;
    NAMESPACE::vector<int> vec;

    for (int i = 1; i < 10; ++i)
        vec.push_back(i);
    
    it = vec.rbegin();

    std::cout << *it << " rbegin\n";
    std::cout << *vec.rend() << " rend\n"; 

    ++it;
    std::cout << *it << " after ++*\n";
    std::cout << *it++ << " after *++\n";
    ++it;
    std::cout << *it << " after --*\n";
    std::cout << *it-- << " after *--\n";
    std::cout << *it << " after --*\n";
    it = it;
    it += 2;
    std::cout << *it << " after += 2\n";
    it -= 2;
    std::cout << *it << " after -= 2\n";

    it2 = vec.rend();
    std::cout << *it << " < " << *it2 << (it < it2) << " operator < \n";
    std::cout << (it > it2) << " operator > \n";
    std::cout << (it >= it2) << " operator >= \n";
    std::cout << (it <= it2) << " operator <= \n";

    std::cout << it[2] << " operator []\n";

    for (int i = 10; i > 1; i--)
        std::cout << it[i] << " ";

    std::cout << "\n***********************************************\n";
    for (it = vec.rbegin(); it != vec.rend(); it++)
        std::cout << *it << "\n";

    std::cout << vec.capacity() << "capacity\n";

}