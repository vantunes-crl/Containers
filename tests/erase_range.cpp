#include "print.hpp"

int main()
{
    std::vector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);
    
    std::cout << *vec.erase(vec.begin() + 1, vec.begin() + 5) << " pos return " << std::endl;

    print(vec);
}