#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include "iterator/iterator.hpp"
#include <typeinfo>

namespace ft
{   /* Tree type to create a binary tree, with parent to help in interator, because we can move back in the tree  */
    template <class T>
    struct Tree
    {
        Tree(const T data, Tree * parent)
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

            /* Constructors */
            binary_tree():_root(nullptr), _size(0)
            {}

            binary_tree &operator=(const binary_tree &cpy)
            {
                clear2(_root);
                _alloc = cpy._alloc;
                ft_cpy(cpy._root);
                _size = cpy._size;
                return *this;
            }

            void clear2(node root)
            {
                if (root == nullptr)    
                    return;
                
                clear2(root->left);
                clear2(root->right);
                deleteNode(root->data.first);
            }

            /*insert function to insert data in the binary tree */
            node insert(T data)
            {
                /* if the tree is empty creates a root */
                if (_root == nullptr)
                {
                    _root = _alloc.allocate(1);
                    _alloc.construct(_root, Tree<T>(data));
                    ++_size;
                    return _root;
                }

                /* create a new 2 nodes copys to hold the previus data and current data */
                node curr;
                node prev;
                curr = _root;

                /* run the entery tree to find the positon to place */
                while (curr != nullptr)
                {
                    /* goes to the left or right depends os the size of the data */
                    /* left smaller right bigger */
                    /* and always save the previus node*/
                    prev = curr;
                    if (curr->data.first > data.first)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }

                /* alloc memory and create a new node and check the leaf to be placed based on the data size */
                if (prev->data.first > data.first)
                {
                    prev->left = _alloc.allocate(1);
                    _alloc.construct(prev->left, Tree<T>(data, prev));
                    ++_size;
                    return prev->left;
                }
                else
                {
                    prev->right = _alloc.allocate(1);
                    _alloc.construct(prev->right, Tree<T>(data, prev));
                    ++_size;
                    return prev->right;
                }
            }

            template< class K > 
            size_t deleteNode(K key)
            {
                node curr = findKey(key);

                if (curr == nullptr)
                    return 0;
                // Case 1: node to be deleted has no children, i.e., it is a leaf node
                if (curr->left == nullptr && curr->right == nullptr)
                {
                    // if the node to be deleted is not a root node, then set its
                    // parent left/right child to null
                    if (curr != _root)
                    {
                        if (curr->parent->left == curr)
                            curr->parent->left = nullptr;
                        else
                            curr->parent->right = nullptr;
                    }
                    else
                        _root = nullptr;
                    _alloc.deallocate(curr, 1);
                }
                else if (curr->left && curr->right) // Case 2: node to be deleted has two children
                {
                    node successor = getMinKey(curr->right);

                    /* save the successor data */
                    T data = successor->data;
                    /* call recursive function to delete the data */
                    deleteNode(successor->data.first);
                    /* const cast to a pointer to modify a const value ex: pair<const key, val> change to pair<key, val> and overide the const key */
                    const_cast<K &>(curr->data.first) = data.first;
                    curr->data.second = data.second;
                }
                else // Case 3: node to be deleted has only one child
                {
                    node child;

                    //choose child
                    if (curr->left)
                        child = curr->left;
                    else
                        child = curr->right;
                    
                    /* if is not the root */
                    if (curr != _root)
                    {
                        /* if the child is on the left/right set parent to child and parent to the proccessor parent */
                        if (curr->parent->left == curr)
                        {
                            child->parent = curr->parent;
                            curr->parent->left = child;            
                        }
                        else
                        {
                            child->parent = curr->parent;
                            curr->parent->right = child;
                        }
                    }
                    else /* if is the root */
                        _root = child;
                   _alloc.deallocate(curr, 1);
                }
                --_size;
                return 1;
            }

            template < class K>
            node findKey(K Key)
            {
                node curr = _root;

                while (curr != nullptr)
                {
                    if (curr->data.first == Key)
                        return curr;
                    if (Key < curr->data.first)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                return nullptr;
            }

            node getMinKey(node curr)
            {
                if (curr == nullptr)
                    return curr;
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

            size_t Size() const
            {
                return _size;
            }

            size_t maxSize() const
            {return _alloc.max_size();}

            ~binary_tree()
            {
               clear(_root);
            }

            void ft_cpy(node root)
            {
                if (root == nullptr)
                    return;

                ft_cpy(root->left);
                insert(root->data);
                ft_cpy(root->right);
            }

        private:
            node _root;
            allocator_type _alloc;
            size_t _size;

            void clear(node root)
            {
                if (root == nullptr)
                    return;
                clear(root->left);
                clear(root->right);
                _alloc.deallocate(root, 1);                
            }

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

            iterator_tree():_root(nullptr) {}

            iterator_tree(node root):_root(root)
            {}

            bool operator==(const iterator_tree &obj2) const
            {return _root == obj2._root;}

            bool operator !=(const iterator_tree &obj2) const
            {return !(*this == obj2);}

            pointer operator->()
            {return &_root->data;}

            reference operator*() const
            {return _root->data;}

            iterator_tree &operator=(const iterator_tree &new_object)
            {
                _root = new_object._root;
                return (*this);
            }

            /* forward iterator */
            iterator_tree &operator++()
            {
                /* if _root is null means we are int he root */
                if (_root == nullptr)
                    return *this;

                /*if right of the leaf is diferent we go to the end of the leaf right */
                if (_root->right != nullptr)
                {
                    binary_tree<T> b;
                    _root = b.getMinKey(_root->right);
                }
                else
                {
                    node parent = _root->parent;
                    while (parent != nullptr && _root == parent->right) 
                    {
                        _root = parent;
                        parent = parent->parent;
                    }
                    _root = parent;
                }
                return *this;
            }

            /* pos increment operator */
            iterator_tree operator++(int)
            {
                iterator_tree temp = *this;
                ++*this;
                return (temp);
            }

            iterator_tree &operator--()
            {
                /* if _root is null means we are int he root */
                if (_root == nullptr)
                    return *this;

                /*if right of the leaf is diferent we go to the end of the leaf left */
                if (_root->left != nullptr)
                {
                    binary_tree<T> b;
                    _root = b.getMaxKey(_root->left);
                }
                else
                {
                    node parent = _root->parent;
                    while (parent != nullptr && _root == parent->left)
                    {
                        _root = parent;
                        parent = parent->parent;
                    }
                    _root = parent;
                }
                return *this;
            }

            iterator_tree operator--(int)
            {
                iterator_tree temp = *this;
                --*this;
                return (temp);
            }

            ~iterator_tree() {}
        private:
            node _root;
    };

    template<class Iterator>
    class bst_reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

            bst_reverse_iterator():_base(iterator_type())
            {}

            explicit bst_reverse_iterator(iterator_type it) : _base(it) {}

            template <class Iter>
            bst_reverse_iterator(const bst_reverse_iterator<Iter> &rev_it) : _base(rev_it._base) {}

            bool operator==(const bst_reverse_iterator &obj2) const
            {return _base == obj2._base;}

            bool operator !=(const bst_reverse_iterator &obj2) const
            {return !(*this == obj2);}

            pointer operator->()
            {return &(operator*());}

            reference operator*() const
            {return *_base;}

            bst_reverse_iterator &operator=(const bst_reverse_iterator &new_object)
            {
                _base = new_object._base;
                return (*this);
            }

            /* forward iterator */
            bst_reverse_iterator &operator++()
            {
                --_base;
                return *this;
            }

            /* pos increment operator */
            bst_reverse_iterator operator++(int)
            {
                bst_reverse_iterator temp = *this;
                --*this;
                return (temp);
            }

            bst_reverse_iterator &operator--()
            {
                ++_base;
                return *this;
            }

            bst_reverse_iterator operator--(int)
            {
                bst_reverse_iterator temp = *this;
                --*this;
                return (temp);
            }

        private:
            iterator_type _base;

    };
}


#endif