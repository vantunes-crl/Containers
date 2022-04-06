#include <iostream>
#include "../../stack.hpp"
#include <stack>

int main ()
{
    ft::stack<int> first;
    ft::stack<int> first2;

    std::cout << first.empty() << " empty \n";

    for (int i = 0; i < 10; ++i)
    {first.push(i);}

     for (int i = 0; i < 5; ++i)
    {first2.push(i);}
    
    // std::cout << first.size() <<  " size my_stack" << std::endl;
    // std::cout << first2.size() << " size stack" << std::endl;

    // std::cout << first.top() << " Top my Stack" << std::endl;
    // std::cout << first2.top() << " Top stack"<< std::endl;

    // while (!first.empty())
    // {
    //     std::cout << first.top() << "\n";
    //     first.pop();
    // }

    // std::cout << first.empty() << " empty \n";

    if (first2 == first)
        std::cout << "equal\n";

    // while (!first2.empty())
    // {
    //     std::cout << first2.top() << "\n";
    //     first2.pop();
    // }

}