#include "../print.hpp"

using namespace ft;
//using namespace std;

int main()
{
    ft::vector<int> vec;
    ft::vector<int>::iterator it;
    int i = -1;

    while (++i < 10)
        vec.push_back(i);
    
   // std::cout << vec.size() << std::endl;
    //*vec.end() = 10;
    //std::cout << *(vec.end() - 1) << std::endl;
    std::cout << "----------------------------------\n";
    std::cout << *vec.insert((vec.end() - 10), 11) << "insert\n";
    print(vec);
}