#ifndef MAP_HPP
#define MAP_HPP

#include "utility/utility.hpp"
#include <iostream>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T map_type;
            typedef Compare key_compare;
            typedef ft::pair<const key_type, map_type> value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;



            map();
            ~map();

        private:
    };
}



#endif