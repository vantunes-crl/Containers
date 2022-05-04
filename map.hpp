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
            typedef Tree<value_type> * node;

            /* iterators */
            typedef iterator_tree<value_type> iterator;
            typedef iterator_tree<const value_type> const_iterator;
            typedef bst_reverse_iterator<const_iterator> const_reverse_iterator;
            typedef bst_reverse_iterator<iterator> reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;


            /*********************************************** Constructors **********************************/
            /* default constructor */
            explicit map (const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type())
            {}

            /* Range constructor */
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                while (first != last)
                {
                    this->insert(make_pair(first->first, first->second));
                    ++first;
                }
            }

            /* Cpy constructor */
            map(const map& x)
            {
                *this = x;
            }

            /******************************* modifiers *****************************************/

            /* insert that verify if the key exists if not insert the data */
            /* return a pair with a interator to the data and false if the key alread exists otherwise true */
            pair<iterator, bool> insert (const value_type& val)
            {   
                node p = _root.findKey(val);
                if (p == nullptr)
                    p = _root.insert(val);
                else
                    return make_pair(iterator(p), false);
                return make_pair(iterator(p), true);
            }

            /* insert and return a iterator to the position */
            iterator insert (iterator position, const value_type &val)
            {
                pair<iterator, bool> p = insert(val);
                return p.first;
            }

            /* insert in a range of elements */
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    this->insert(make_pair(first->first, first->second));
                    ++first;
                }
            }


            /***************************** iterators *********************************/

            /* return the minimum left key , inorder */
            iterator begin()
            {
                return (iterator(_root.getMinKey(_root.getRoot())));
            }

            /* return a const iterator to the begin */
            const_iterator begin() const
            {
                return (iterator(_root.getMinKey(_root.getRoot())));
            }

            /* return a nullptr iterator */
            const_iterator end() const
            {
                return iterator();
            }

            /* return a nullptr iterator */
            iterator end()
            {
                return iterator();
            }

            /* return a const iterator to the end */
            reverse_iterator rbegin()
            {
                return reverse_iterator(_root.getMaxKey(_root.getRoot()));
            }

            /* return a nullptr iterator */
            reverse_iterator rend()
            {
                return reverse_iterator();
            }

            /******************************************************* capacity ******************************************/
            /* return the tree size */
            size_t size() const
            {
                return _root.Size();
            }

            bool empty() const
            {
                return _root.Size();
            }

            size_type max_size() const
            {return _root.maxSize();}

            /****************************************************** element access ************************************/
            map_type &operator[] (const key_type &k)
            {
                pair<iterator, bool> p = insert(make_pair(k, map_type()));
                return p.first->second;
            }


            

            ~map() {}

        private:
            bst _root;

    };
}



#endif