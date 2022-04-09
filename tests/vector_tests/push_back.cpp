#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int> vec;
    int i = -1;

    while (++i < 10)
        vec.push_back(i);

    print(vec);
}