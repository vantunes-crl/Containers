#include <iostream>

class TreeNode
{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data)
        {
            this->left = nullptr;
            this->right = nullptr;
            this->data = data;
        }
};

class binary_tree
{
    public:
        TreeNode *root;
        binary_tree()
        {this->root = nullptr;}


        void addNode(int data)
        {
            TreeNode *node = new TreeNode(data);
            if (root == nullptr)
                root = node;
            else
            {
                TreeNode *find = this->root;
                while (find != nullptr)
                {
                    if (find->data >= data)
                    {
                        if (find->left == nullptr)
                        {
                            find->left = node;
                            return;
                        }
                        else
                            find = find->left;
                    }
                    else
                    {
                        if (find->right == nullptr)
                        {
                            find->right = node;
                            return;
                        }
                        else
                            find = find->right;
                    }
                }
            }
        }

    void preorder(TreeNode *node)
	{
		if (node != nullptr)
		{
			// Display node value
			std::cout << "  " << node->data;
			// Visit to left subtree
			this->preorder(node->left);
			// Visit to right subtree
			this->preorder(node->right);
		}
	}

	void inorder(TreeNode *node)
	{
		if (node != nullptr)
		{
			// Visit to left subtree
			this->inorder(node->left);
			// Display node value
			std::cout << "  " << node->data;
			// Visit to right subtree
			this->inorder(node->right);
		}
	}

	void postorder(TreeNode *node)
	{
		if (node != nullptr)
		{
			// Visit to left subtree
			this->postorder(node->left);
			// Visit to right subtree
			this->postorder(node->right);
			// Display node value
			std::cout << "  " << node->data;
		}
	}

    ~binary_tree();
};

int main()
{
	binary_tree *tree = new binary_tree();
	/*
	         10
	        / \
	       /   \
	      4     15
	     / \   /
	    3   5 12
	    -------------
	    Build binary search tree

	*/
	tree->addNode(10);
	tree->addNode(4);
	tree->addNode(3);
	tree->addNode(5);
	tree->addNode(15);
	tree->addNode(12);
	// Display tree nodes
	std::cout << "Preorder " << std::endl;
	tree->preorder(tree->root);
	std::cout << "\nInorder " << std::endl;
	tree->inorder(tree->root);
	std::cout << "\nPostorder " << std::endl;
	tree->postorder(tree->root);
	return 0;
}