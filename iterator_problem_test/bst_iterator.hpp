#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

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

            bst_iterator() {}

            bst_iterator(node root):_root(root)
            {}

            // bst_iterator &operator=(const bst_iterator &new_object)
            // {
            //     _tree = new_object._tree;
            //     return (*this);
            // }

            // bool operator==(const bst_iterator &obj2) const
            // {return _tree == obj2._tree;}

            // bool operator !=(const bst_iterator &obj2) const
            // {return !(*this == obj2);}

            // pointer operator->()
            // {return _root;}
            
            // reference operator*() const
            // {return *_root;}

            // bst_iterator &operator++()
            // {
            //     if (_root == nullptr)
            //         return *this;

            //     if (_root->right == nullptr)
            //     {
            //         if (_root->data.first > _root->parent->data.first)
            //         {
            //             while (_root->data.first > _root->parent->data.first && _root->parent->parent)
            //                 _root = _root->parent;
            //             _root = _root->parent;
            //         }
            //         else
            //             _root = _root->parent;

            //         return *this;
            //     }
            //     else
            //     {
            //         _root = minKey(_root->right);
            //         return *this;
            //     }
            // }

            // bst_iterator operator++(int)
            // {

            // }

            // node minKey(node curr)
            // {
            //     while (curr->left != nullptr) {
            //         curr = curr->left;
            //     }
            //     return curr;
            // }

            // bool operator<(bst_iterator &obj2) const
            // {return _list < obj2._list;}

            // bool operator>(bst_iterator &obj2) const
            // {return _list > obj2._list;}

            // bool operator<=(bst_iterator &obj2) const
            // {return _list <= obj2._list;}

            // bool operator>=(bst_iterator &obj2) const
            // {return _list >= obj2._list;}


            ~bst_iterator() 
            {
            }

        private:
           node _root;
    };
}


#endif