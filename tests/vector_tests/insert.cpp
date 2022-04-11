#include "../print.hpp"


int main()
{
    NAMESPACE::vector<int> vec;
    NAMESPACE::vector<int>::iterator it;
    int i = -1;

    while (++i < 10)
        vec.push_back(i);
    
    std::cout << *vec.insert((vec.end() - 10), 11) << "insert\n";
    print(vec);
}