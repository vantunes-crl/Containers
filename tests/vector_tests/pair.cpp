#pragma clang diagnostic ignored "-Wc++11-extensions"

#include "../print.hpp"

int main()
{
    {
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
 
    // build a pair from two ints
    auto p1 = NAMESPACE::make_pair(n, a[1]);
    std::cout << "The value of p1 is " << "(" << p1.first << ", " << p1.second << ")\n";
 
    // build a pair from a reference to int and an array (decayed to pointer)
    auto p2 = NAMESPACE::make_pair(std::ref(n), a);
    n = 7;
    std::cout << "The value of p2 is " << "(" << p2.first << ", " << *(p2.second + 2) << ")\n";
    }

    {
        NAMESPACE::pair <int,int> foo;
        NAMESPACE::pair <int,int> bar;

        foo = NAMESPACE::make_pair (10,20);
        bar = NAMESPACE::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    }

}