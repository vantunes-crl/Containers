#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include "iterator/iterator.hpp"

namespace ft
{
    template <class T>
    struct Tree
    {
        Tree(T data, Tree * parent)
        :data(data), left(nullptr), right(nullptr), parent(parent) {}

        Tree(T data)
        :data(data), left(nullptr), right(nullptr), parent(nullptr) {}

        T data;
        Tree *left;
        Tree *right;
        Tree *parent;
    };

    template <class T, class Alloc = std::allocator<Tree<T> > >
    class binary_tree
    {
        public:
            typedef Alloc allocator_type;
            typedef Tree<T> * node;

            binary_tree():_root(nullptr), _size(0)
            {}

            node insert(T data)
            {
                if (_root == nullptr)
                {
                    _root = _alloc.allocate(1);
                    _alloc.construct(_root, Tree<T>(data));
                    return _root;
                }
                
                node curr;
                node prev;

                curr = _root;

                while (curr != nullptr)
                {
                    prev = curr;
                    if (curr->data > data)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }

                if (prev->data > data)
                {
                    prev->left = _alloc.allocate(1);
                    _alloc.construct(prev->left, Tree<T>(data, prev));
                    return prev->left;
                }
                else
                {
                    prev->right = _alloc.allocate(1);
                    _alloc.construct(prev->right, Tree<T>(data, prev));
                    return prev->right;
                }
            }

            node findKey(T Key)
            {
                node curr = _root;
                node parent = nullptr;

                while (curr != nullptr && curr->data.first != Key.first)
                {
                    parent = curr;
                    if (Key < curr->data)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                return parent;
            }

            node getMinKey(node curr)
            {
                while (curr->left != nullptr) {
                    curr = curr->left;
                }
                return curr;
            }

            node getMaxKey(node curr)
            {
                while (curr->right != nullptr) {
                    curr = curr->right;
                }
                return curr;
            }

            node getRoot()
            {
                return _root;
            }

            allocator_type getAllocator()
            {
                return _alloc;
            }

            ~binary_tree()
            {}
        
            
        private:
            node _root;
            allocator_type _alloc;
            size_t _size;

            // void clear(node root)
            // {
            //     if (root == nullptr)
            //         return;

            //     clear(root->left);
            //     _alloc.deallocate(root, sizeof(root));
            //     clear(root->right);
            // }

    };

    template<class T>
    class iterator_tree
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

            iterator_tree() {}

            iterator_tree(node root):_root(root)
            {}

            pointer operator->()
            {return &_root->data;}
            
            reference operator*() const
            {return *_root->data;}

            iterator_tree &operator=(const iterator_tree &new_object)
            {
                _root = new_object._root;
                return (*this);
            }

            iterator_tree &operator++()
            {
                if (_root == nullptr)
                    return *this;

                if (_root->right == nullptr)
                {
                    if (_root->data.first > _root->parent->data.first)
                    {
                        while (_root->data.first > _root->parent->data.first && _root->parent->parent)
                            _root = _root->parent;
                        _root = _root->parent;
                    }
                    else
                        _root = _root->parent;
                    return *this;
                }
                else
                {
                    binary_tree<T> b;
                    _root = b.getMinKey(_root->right);
                    return *this;
                }
            }


            ~iterator_tree() {}
        private:
            node _root;
    };
}


#endif