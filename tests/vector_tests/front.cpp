#include "print.hpp"

int main()
{
    ft::vector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    vec.front() = 5;

    std::cout << vec.front() << std::endl;
}