#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int> vec;
    int i = -1;

    while (++i < 5000)
        vec.push_back(i);

    print(vec);
}