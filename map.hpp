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
            :_root(), _alloc(_root.getAllocator())
            {}

            /* Range constructor */
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            :_root(), _alloc(_root.getAllocator())
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

            /******************************** operator overload *********************************/

            map &operator=(const map &cpy)
            {
                _root = cpy._root;
                return *this;
            }

            /******************************* modifiers *****************************************/

            /* insert that verify if the key exists if not insert the data */
            /* return a pair with a interator to the data and false if the key alread exists otherwise true */
            pair<iterator, bool> insert (const value_type &val)
            {   
                node p = _root.findKey(val.first);
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

            size_t erase(const key_type &k)
            {
                if (_root.deleteNode(k))
                    return 1;
                return 0;
            }

            void erase (iterator position)
            {
                erase(position->first);
            }

            void erase (iterator first, iterator last)
            {
                while (first != last)
                {
                    erase(first->first);
                    ++first;
                }
            }

            /* swap contents */
            void swap (map &x)
            {
                map<key_type, map_type> temp;
                temp = *this;
                *this = x;
                x = temp;
            }

            /* clear all data */
            void clear()
            {
                _root.clear2(_root.getRoot());
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

            /****************************************************** observers *****************************************/


            // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            /*  Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second */
            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                protected:
                    key_compare comp;
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;

                    bool operator()(const value_type &x, const value_type &y) const
                    {
                        return comp(x.first, y.first);
                    }
                    value_compare(const key_compare &c = key_compare()) : comp(c) {}
            };

            /* return key comparison object use std::less<Key> whith is the same of < but work with built-in types */
            key_compare key_comp() const
            {
                return key_compare();
            }

            /* return value comparation object */
            value_compare value_comp() const
            {
                return value_compare();
            }

            /************************************************  Operations **************************************************/

            /* find a element by key and return a iterator */
            iterator find (const key_type &k)
            {
                return _root.findKey(k);
            }

            /* find a element by key and return a const iterator */
            const_iterator find (const key_type &k) const
            {
                return _root.findKey(k);
            }

            /* Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise). */
            size_type count (const key_type& k) const
            {
                if(_root.findKey(k))
                    return 1;
                return 0;
            }

            iterator lower_bound (const key_type& k)
            {
                
            }

            const_iterator lower_bound (const key_type& k) const
            {


            }




            ~map() {}

        private:
            bst _root;
            allocator_type _alloc;

    };
}



#endif