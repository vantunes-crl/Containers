#include "print.hpp"
#include <vector>

using namespace ft;

int main()
{
    vector<int>::reverse_iterator it;
    vector<int>::reverse_iterator it2;
    vector<int> vec;

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

    it2 = vec.rend() - 1;
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
    //print(vec);
    std::cout << vec.capacity() << "capacity\n";

    //diff 
    // 15c15
    // < 0 0 81 0 1 2 3 4 5 memory random number
    // ---
    // > 5 0 49 0 1 2 3 4 5 memory random number
    // 26c26
    // < 16capacity /*capacity in the real vector allocate more then necessary*/
    // ---
    // > 9capacity
}