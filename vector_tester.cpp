#include <vector>
#include <iterator>
#include <iostream>

#define SIZE 10
#define TYPE int
using namespace std;
int main()
{
    vector<TYPE> vec;
    vector<TYPE>::iterator it;

    std::cout << "*******************************Push Back Test***********************************\n";
    for (size_t i = 0; i < SIZE; ++i)
        vec.push_back(i);
    std::cout << "________________________________normal________________________________\n";
    for(unsigned i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << std::endl;
    
    std::cout << "________________________________iterator________________________________\n";
    for(it = vec.begin(); it != vec.end(); ++it)
        std::cout << (*it) << '\n';

    std::cout << "*******************************Pop back Test***********************************\n";
    for (size_t i = 0; i < SIZE / 2; ++i)
        vec.pop_back();

    std::cout << "________________________________normal________________________________\n";

    for(unsigned i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << std::endl;
    
    std::cout << "________________________________iterator________________________________\n";
    for(it = vec.begin(); it != vec.end(); ++it)
        std::cout << (*it) << '\n';

    std::cout << "******************************* Copy constructor test ***********************************\n";
    for (size_t i = 0; i < SIZE; ++i)
        vec.push_back(i);
    vector<TYPE> vec2;
    vec2 = vec;
    std::cout << "________________________________normal________________________________\n";

    for(unsigned i = 0; i < vec2.size(); ++i)
        std::cout << vec2[i] << std::endl;
    
    std::cout << "________________________________iterator________________________________\n";
    for(it = vec2.begin(); it != vec2.end(); ++it)
        std::cout << (*it) << '\n';
    
    std::cout << "******************************* Copy Contructor overload ***********************************\n";

    vector<TYPE> vec3(vec2);
    std::cout << "________________________________normal________________________________\n";

    for(unsigned i = 0; i < vec2.size(); ++i)
        std::cout << vec3[i] << std::endl;
    
    std::cout << "________________________________iterator________________________________\n";
    for(it = vec3.begin(); it != vec3.end(); ++it)
        std::cout << (*it) << '\n';
    
    std::cout << "******************************* begin test ***********************************\n";
    std::cout << *vec.begin() <<  std::endl;
    vec[0] = 10;
    std::cout << *vec.begin()  << std::endl;
    std::cout << "******************************* end test ***********************************\n";
    std::cout << *vec.end() <<  std::endl;
    it = vec.end();
    *it = 10;
    std::cout << *vec.end()  << std::endl;
    std::cout << "******************************* rbegin  rend test ***********************************\n";
    vector<TYPE>::reverse_iterator rit;
    rit = vec.rbegin();
    *rit = 20;
    for (rit = vec.rbegin(); rit != vec.rend(); rit++)
        cout << *rit << "\n";
    rit = vec.rend() - 1;
    *rit = 21;
    for (rit = vec.rbegin(); rit != vec.rend(); rit++)
        cout << *rit << "\n";
    std::cout << "******************************* Capacity tests ***********************************\n";
    std::cout << vec.size() << "Size "<< std::endl;
    std::cout << vec.max_size() << " Max_size " << std::endl;
    vec.resize(100);
    std::cout << vec.capacity() << " Capacity after resize 100\n";
    std::cout << vec.size() << " Size after resize 100\n";
    std::cout << vec.empty() << " Empty\n";
    vec.reserve(200);
    std::cout << vec.capacity() << " Capacity after reserve 200\n";
    vec.capacity();


}