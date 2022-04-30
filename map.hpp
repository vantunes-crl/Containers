#ifndef MAP_HPP
#define MAP_HPP

#include "utility/utility.hpp"
#include <iostream>
#include "iterator/iterator.hpp"
#include "binary_tree.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T map_type;
            typedef Compare key_compare;
            typedef pair<const key_type, map_type> value_type;
            typedef Alloc allocator_type;

            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef binary_tree<value_type> bst;
            typedef size_t size_type;

            /* iterators */
            typedef iterator_tree<value_type> iterator;
            typedef iterator_tree<const value_type> const_iterator;
            typedef reverse_iterator<const_iterator> const_reverse_iterator;
            typedef reverse_iterator<iterator> reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            :_size(0)
            {}

            pair<iterator, bool> insert (const value_type& val)
            {
                Tree<value_type> *p = _root.insert(val);

                return make_pair(iterator(p), true);
            }

            iterator begin()
            {
                return (iterator(_root.getMinKey(_root.getRoot())));
            }


            ~map() {}

        private:
            size_type _size;
            bst _root;
            


    };
}



#endif