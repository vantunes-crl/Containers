#ifndef BST_ITERATOR2_HPP
#define BST_ITERATOR2_HPP

#include "binary_tree.hpp"

namespace ft
{
    template<class U>
    class bsc_iterator2
    {
        //typedef Tree<T> * node;

        private:
            Tree<U> * node;
        public:
            bsc_iterator2() {}
            ~bsc_iterator2() {}
    };
}




#endif