#include <iostream>

class Node
{
public:
    Node() = default;
    Node(int val) {this->val = val;}
    ~Node();
    bool hasChild();
    int getChildrenNum();

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
    bool remove(int val);
    Node *removeHelp(Node *subroot, int val);
    bool find(int val);
    int findMax();
    int findMaxHelp(Node *subroot);
    int findMin();
    int findMinHelp(Node *subroot);
    bool isEmpty();
    int getHeight();
    int getHeightHelp(Node *subroot);
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

bool Node::hasChild()
{
    if (left != nullptr || right != nullptr)
        return true;
    return false;
}

int Node::getChildrenNum()
{
    if (left == nullptr && right == nullptr)
        return 0;
    if (left != nullptr && right != nullptr)
        return 2;
    return 1;
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

bool BST::remove(int val)
{

    return false;
}

Node *BST::removeHelp(Node *subroot, int val)
{
    if (root == nullptr || subroot == nullptr)
        return nullptr;
    if (val < subroot->val)
        subroot->left = removeHelp(subroot->left, val);
    if (val > subroot->val)
        subroot->right = removeHelp(subroot->right, val);
    // val == subroot->val
    if (subroot->getChildrenNum() != 1)
    {

    }
    return subroot;
}

bool BST::find(int val)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (val == temp->val)
            return true;
        if (val < temp->val)
            temp = temp->left;
        else if (val > temp->val)
            temp = temp->right;
    }
    return false;
}

int BST::findMax()
{
    return findMaxHelp(root);
}

int BST::findMaxHelp(Node *subroot)
{
    while (subroot->right != nullptr)
        subroot = subroot->right;
    return subroot->val;
}

int BST::findMin()
{
    return findMinHelp(root);
}

int BST::findMinHelp(Node *subroot)
{
    while (subroot->left != nullptr)
        subroot = subroot->left;
    return subroot->val;
}

bool BST::isEmpty()
{
    if (root == nullptr)
        return true;
    return false;
}

int BST::getHeight()
{
    return getHeightHelp(root);
}

int BST::getHeightHelp(Node *subroot)
{
    if (subroot == nullptr)
        return 0;
    int leftHeight = getHeightHelp(subroot->left);
    int rightHeight = getHeightHelp(subroot->right);
    int height = leftHeight > rightHeight ? leftHeight + 1: rightHeight + 1;
    return height;
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