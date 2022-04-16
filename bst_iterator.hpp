#ifndef BSC_ITERATOR_HPP
#define BSC_ITERATOR_HPP

#include "iterator/iterator.hpp"
#include "binary_tree.hpp"

namespace ft
{
    template <class T>
    class bst_iterator
    {
        public:
            typedef T value_type;
            typedef value_type & reference;
            typedef value_type const & const_reference;
            typedef value_type * pointer;
            typedef value_type const * const_pointer;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef bidirectional_iterator_tag iterator_category;
            typedef Tree<T> * node;

            bst_iterator():_tree(nullptr) {}

            bst_iterator(node tree):_tree(tree) {}

            bst_iterator &operator=(const bst_iterator &new_object)
            {
                _tree = new_object._tree;
                return (*this);
            }

            bool operator==(const bst_iterator &obj2) const
            {return _tree == obj2._tree;}

            bool operator !=(const bst_iterator &obj2) const
            {return !(*this == obj2);}

            pointer operator->()
            {return &_tree->data;}
            
            reference operator*() const
            {return *_tree->data;}

            bst_iterator &operator++()
            {
                
            }

            // bst_iterator operator++(int)
            // {
            //     bst_iterator temp = *this;
            //     ++*this;
            //     return (temp);
            // }

            // bst_iterator &operator--()
            // {--_tree; return *this;}

            // bst_iterator operator--(int)
            // {
            //     bst_iterator<T> temp = *this;
            //     --*this;
            //     return (temp);
            // }
            
            bst_iterator  operator+(difference_type n)
            {return (_tree + n);}

            bst_iterator  operator-(difference_type n)
            {return (_tree - n);}

            bst_iterator operator-=(difference_type n)
            {return _tree -= n;}

            bst_iterator operator+=(difference_type n)
            {return _tree += n;}

            bool operator<(bst_iterator &obj2) const
            {return _tree < obj2._tree;}

            bool operator>(bst_iterator &obj2) const
            {return _tree > obj2._tree;}

            bool operator<=(bst_iterator &obj2) const
            {return _tree <= obj2._tree;}

            bool operator>=(bst_iterator &obj2) const
            {return _tree >= obj2._tree;}

            reference operator[](difference_type n) const
            {return _tree[n];}


            ~bst_iterator() {}
        private:
            node _tree;
    };
}


#endif