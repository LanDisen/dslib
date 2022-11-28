#include <iostream>

class Node
{
public:
    Node() = default;
    Node(int val) {this->val = val;}
    ~Node();

public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
};

class BST
{
public:
    BST() = default;
    ~BST();
    bool insert(int val);
    Node *insertHelp(Node *subroot, int val);
    bool remove(const int& val);
    Node *removeHelp(Node *subroot, int val);
    bool find(int val);
    int getHeight();
    void preorder();
    void preorderHelp(Node *subroot);
    void inorder();
    void inorderHelp(Node *subroot);
    void postorder();
    void postorderHelp(Node *subroot);

public:
    Node *root = nullptr;
};

Node::~Node()
{
    if (left != nullptr)
    {
        delete left;
        left = nullptr;
    }
    if (right != nullptr)
    {
        delete left;
        right = nullptr;
    }
}

BST::~BST()
{
    if (root != nullptr)
    {
        delete root;
        root = nullptr;
    }
}

bool BST::insert(int val)
{
    if (insertHelp(root, val) == nullptr)
        return false;
    return true;
}

Node *BST::insertHelp(Node *subroot, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return root;
    }
    if (subroot == nullptr)
    {
        subroot = new Node(val);
        return subroot;
    }
    if (val < subroot->val)
        subroot->left = insertHelp(subroot->left, val);
    if (val > subroot->val)
        subroot->right = insertHelp(subroot->right, val);
    return subroot;
}

void BST::preorder()
{
    preorderHelp(root);
    std::cout << std::endl;
}

void BST::preorderHelp(Node *subroot)
{
    if (subroot == nullptr)
        return;
    std::cout << subroot->val << " ";
    preorderHelp(subroot->left);
    preorderHelp(subroot->right);
}

void BST::inorder()
{
    inorderHelp(root);
    std::cout << std::endl;
}

void BST::inorderHelp(Node *subroot)
{
    if (subroot == nullptr)
        return;
    inorderHelp(subroot->left);
    std::cout << subroot->val << " ";
    inorderHelp(subroot->right);
}

void BST::postorder()
{
    postorderHelp(root);
    std::cout << std::endl;
}

void BST::postorderHelp(Node *subroot)
{
    if (subroot == nullptr)
        return;
    postorderHelp(subroot->left);
    postorderHelp(subroot->right);
    std::cout << subroot->val << " ";
}