#include "../print.hpp"

int main()
{
    NAMESPACE::vector<int> vec;
    int i = -1;

    while (++i < 50)
        vec.push_back(i);

    i = -1;
    while (++i < 10)
        vec.pop_back();

    print(vec);
}