#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int> vec;
    int i = -1;

    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    vec.push_back(1);
    std::cout << vec.capacity() << " Capacity\n";
    std::cout << vec.size() << " Size\n";

    print(vec);
}