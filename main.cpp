#include "vector.hpp"
//#include <vector>
//#include "test/print.hpp"
using namespace ft;
#include "tests/print.hpp"

int main()
{
    vector<int> vec(10,7);
    vector<int> vec2;

    int n = 10;
    int b = 20;

    vec2.assign(vec.begin(), vec.end());
    print(vec2);
    std::cout << "-------------------------\n";
    vec2.assign(n, b);
    print(vec2);

   
}