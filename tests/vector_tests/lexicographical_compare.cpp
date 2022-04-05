#include "../lexicographical_compare.hpp"
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<char> v1('a', 'a');
    std::vector<char> v2('a', 'x');
    std::vector<char>::iterator it;

    std::cout << lexicographical_compare(v1.begin(),  v1.end(), v2.begin(),  v2.end()) << std::endl;   

}