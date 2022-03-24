#include "vector.hpp"
#include <vector>
#include "test/print.hpp"
using namespace ft;

int main()
{
    vector<int> vec;

    for (int i = 0; i < 10; ++i)
        vec.push_back(1);
    
    print(vec);
}