#include "../print.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec;

    for (int i = 0; i < 20; ++i)
        vec.push_back(i);

    vec.clear();
    print(vec);
}