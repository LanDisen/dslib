#include <iostream>

class Node
{
public:
    Node() = default;
    Node(int data) {this->data = data;}
    ~Node();
    bool isLeaf();
    bool hasChild();
    int getChildrenNum();

public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
};

class BST
{
public:
    BST() = default;
    ~BST();
    bool insert(int data);
    Node *insertHelp(Node *subroot, int data);
    bool remove(int data);
    Node *removeHelp(Node *subroot, int data);
    Node *find(int data);
    bool isExist(int data);
    int findMax();
    Node *findMaxHelp(Node *subroot);
    int findMin();
    Node *findMinHelp(Node *subroot);
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

bool Node::isLeaf()
{
    if (left == nullptr && right == nullptr)
        return true;
    return false;
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

bool BST::insert(int data)
{
    if (insertHelp(root, data) == nullptr)
        return false;
    return true;
}

Node *BST::insertHelp(Node *subroot, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }
    if (subroot == nullptr)
    {
        subroot = new Node(data);
        return subroot;
    }
    if (data < subroot->data)
        subroot->left = insertHelp(subroot->left, data);
    if (data > subroot->data)
        subroot->right = insertHelp(subroot->right, data);
    return subroot;
}

bool BST::remove(int data)
{
    if (!isExist(data))
        return false;
    removeHelp(root, data);
    return true;
}

Node *BST::removeHelp(Node *subroot, int data)
{
    if (root == nullptr || subroot == nullptr)
        return nullptr;
    if (data < subroot->data)
        subroot->left = removeHelp(subroot->left, data);
    else if (data > subroot->data)
        subroot->right = removeHelp(subroot->right, data);
    // data == subroot->data
    else 
    {
        Node *temp;
        if (subroot->left!=nullptr && subroot->right!=nullptr)
        {
            temp = findMinHelp(subroot->right);
            subroot->data = temp->data;
            subroot->right = removeHelp(subroot->right, subroot->data);
        }
        else
        {
            temp = subroot;
            if (subroot->right == nullptr)
                subroot = subroot->left;
            else if (subroot->left == nullptr)
                subroot = subroot->right;
            delete temp;
            temp = nullptr;
        }
        return subroot;
    }
    return subroot;
}

Node *BST::find(int data)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (data == temp->data)
            return temp;
        if (data < temp->data)
            temp = temp->left;
        else if (data > temp->data)
            temp = temp->right;
    }
    return nullptr;
}

bool BST::isExist(int data)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (data == temp->data)
            return true;
        if (data < temp->data)
            temp = temp->left;
        else if (data > temp->data)
            temp = temp->right;
    }
    return false;
}

int BST::findMax()
{
    return findMaxHelp(root)->data;
}

Node *BST::findMaxHelp(Node *subroot)
{
    if (subroot->isLeaf())
        return subroot;
    while (subroot->right != nullptr)
        subroot = subroot->right;
    return subroot;
}

int BST::findMin()
{
    return findMinHelp(root)->data;
}

Node *BST::findMinHelp(Node *subroot)
{
    if (subroot->isLeaf())
        return subroot;
    while (subroot->left != nullptr)
        subroot = subroot->left;
    return subroot;
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
    std::cout << subroot->data << " ";
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
    std::cout << subroot->data << " ";
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
    std::cout << subroot->data << " ";
}