#include "../print.hpp"
#include <iostream>

int main()
{
    {
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
 
    // build a pair from two ints
    auto p1 = ft::make_pair(n, a[1]);
    std::cout << "The value of p1 is " << "(" << p1.first << ", " << p1.second << ")\n";
 
    // build a pair from a reference to int and an array (decayed to pointer)
    auto p2 = ft::make_pair(std::ref(n), a);
    n = 7;
    std::cout << "The value of p2 is " << "(" << p2.first << ", " << *(p2.second + 2) << ")\n";
    }

    {
        ft::pair <int,int> foo;
        ft::pair <int,int> bar;

        foo = ft::make_pair (10,20);
        bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    }

}