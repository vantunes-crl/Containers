#include "../print.hpp"
 
int main()
{
    NAMESPACE::vector<char> v1('a', 'a');
    NAMESPACE::vector<char> v2('a', 'x');
    NAMESPACE::vector<char>::iterator it;

    std::cout << lexicographical_compare(v1.begin(),  v1.end(), v2.begin(),  v2.end()) << std::endl;   

}