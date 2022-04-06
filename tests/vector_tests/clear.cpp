#include "../print.hpp"

int main()
{
    ft::vector<int> vec;

    for (int i = 0; i < 20; ++i)
        vec.push_back(i);

    vec.clear();
    print(vec);
}