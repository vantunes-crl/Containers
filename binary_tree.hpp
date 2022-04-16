#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>

namespace ft
{
    template <class T>
    struct Tree
    {
            Tree(T data)
            :data(data), left(nullptr), right(nullptr) {}

            Tree()
            :data(data), left(nullptr), right(nullptr) {}

            T data;
            Tree *left;
            Tree *right;
    };

    template <class T, class Alloc = std::allocator<Tree<T> > >
    class binary_tree
    {
        public:
            typedef Alloc allocator_type;
            typedef Tree<T> * node;

            node insert(T value)
            {
                if (_root == nullptr)
                {
                    _root = _alloc.allocate(1);
                    _alloc.construct(_root, value);
                    return _root;
                }

                node curr;
                node prev;

                curr = _root;
                while (curr != nullptr)
                {
                    prev = curr;

                    if (curr->data > value)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }

                if (prev->data > value)
                {
                    prev->left = _alloc.allocate(1);
                    _alloc.construct(prev->left, value);
                    return prev->left;
                }
                else
                {
                    prev->right = _alloc.allocate(1);
                    _alloc.construct(prev->right, value);
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

            void remove(T Key)
            {
                node parent = nullptr;
                node curr = _root;

                while (curr != nullptr && curr->data.first != Key.first)
                {
                    parent = curr;
                    if (Key.first < curr->data.first)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                if (curr == nullptr)
                    std::cout << "Key not found\n";
                
                if (!curr->left && !curr->right)  //case 1 node to be deleted has no children, i.e., it is a leaf node
                {
                    if (curr != _root)
                    {
                        if (parent->left == curr)
                            parent->left = nullptr;
                        else
                            parent->right = nullptr;
                    }    
                    else
                        _root = nullptr;
                    std::cout << "case 1\n";
                }
                else if (curr->left && curr->right) //case 2 node to be deleted has two children
                {
                    node sucessor = getMinKey(curr->right);

                    T data = sucessor->data;

                    std::cout << "case 2\n";
                    remove(sucessor->data);
                    curr->data = data;
                }
                else //case 3 node to be deleted has only one child
                {
                    node child;

                    if (curr->left)
                        child = curr->left;
                    else
                        child = curr->right;
                    
                    if (curr != _root)
                    {
                        if (curr == parent->left)
                            parent->left = child;
                        else
                            parent->right = child;
                    }
                    else
                        _root = child;
                    std::cout << "case 3\n";
                    
                }
                _alloc.deallocate(curr, sizeof(curr));
            }


            void inorder(node root)
            {
                if (root == nullptr)
                    return;
                
                inorder(root->left);
                std::cout << root->data.first << root->data.second << std::endl;
                inorder(root->right);
            }

            node getRoot()
            {
                return _root;
            }

            allocator_type getAllocator()
            {
                return _alloc;
            }

            binary_tree():_root(nullptr)
            {}

            ~binary_tree()
            {clear(_root);}

        private:
            node _root;
            allocator_type _alloc;

            void clear(node root)
            {
                if (root == nullptr)
                    return;

                clear(root->left);
                _alloc.deallocate(root, sizeof(root));
                clear(root->right);
            }
    };
}


#endif