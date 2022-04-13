#ifndef MAP_HPP
#define MAP_HPP

#include "utility/utility.hpp"
#include <iostream>
#include "iterator/iterator.hpp"

template < class T > 
class BinaryTree
{
    public:
        BinaryTree *left;
        BinaryTree *right;
        T data;
        BinaryTree(T data)
        :data(data)
        {
            left = right = nullptr;
        }

        ~BinaryTree() {}
    private:
        

};

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
            typedef size_t size_type;

            /* iterators */
            typedef random_access_iterator<value_type> iterator;
            typedef random_access_iterator<const value_type> const_iterator;
            typedef reverse_iterator<const_iterator> const_reverse_iterator;
            typedef reverse_iterator<iterator> reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            :_root(nullptr), _size(0), _alloc(alloc)
            {}

            pair<iterator, bool> insert (const value_type& val)
            {
                pair<iterator, bool> par;

                if (_root == nullptr)
                {
                    _root = _alloc.allocate(1);
                    _alloc.construct(_root, BinaryTree<value_type>(val));
                    //std::cout << "root " << _root->data.first << " " << _root->data.second << std::endl;
                }
                return par;

            }

            ~map() {}

        private:
            size_type _size;
            allocator_type _alloc;
            pointer _root;


    };
}



#endif