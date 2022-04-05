#include "print.hpp"

using namespace ft;
//using namespace std;

int main()
{
    ft::vector<char> vec;
    ft::vector<char>::iterator it;
    int i = 48;

    while (++i < 58)
        vec.push_back(i);
    
   // std::cout << vec.size() << std::endl;
    //*vec.end() = 10;
    //std::cout << *(vec.end() - 1) << std::endl;
    std::cout << "----------------------------------\n";
    vec.insert((vec.end() - 6), 10, 49);
    print(vec);
}