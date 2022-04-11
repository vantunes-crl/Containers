#include "../print.hpp"

int main()
{
    NAMESPACE::vector<char> vec;
    NAMESPACE::vector<char>::iterator it;
    int i = 48;

    while (++i < 58)
        vec.push_back(i);

    vec.insert((vec.end() - 6), 10, 49);
    print(vec);
}