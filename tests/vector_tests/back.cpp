#include "../print.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    vec.back() = 5;

    std::cout << vec.back() << std::endl;
}