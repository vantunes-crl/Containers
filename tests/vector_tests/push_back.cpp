#include "../print.hpp"

using namespace ft;
//using namespace std;

int main()
{
    vector<int> vec;
    int i = -1;

    while (++i < 10)
        vec.push_back(i);

    print(vec);
}