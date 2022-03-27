#include "vector.hpp"
#include <vector>
#include "test/print.hpp"
using namespace ft;

int main()
{
    vector<int>::reverse_iterator it;
    //vector<int>::iterator it;
    vector<int> vec;

    for (int i = 0; i < 20; ++i)
    {
        vec.push_back(i);
        std::cout << i << std::endl;
    }
    std::cout << "*****************************************\n";
    std::cout << "*****************************************\n";
    
    //  for (it2 = vec.begin(); it2 != vec.end(); ++it2)
    //     std::cout << *it << std::endl;


    it = vec.rbegin();
    std::cout << *it << "rbegin \n";

    it = vec.rend();
    std::cout << *it << "rend\n";


    for (it = vec.rbegin(); it != vec.rend(); ++it)
        std::cout << *it << std::endl;


}