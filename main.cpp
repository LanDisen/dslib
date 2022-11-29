#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
using namespace std;

template<typename T>
void print(T t)
{
    cout << t;
}

template<typename T>
void println(T t)
{
    cout << t << endl;
}

void testStack()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
}

void testQueue()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.front() << endl;
    cout << q.rear() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.enqueue(40);
    cout << q.rear() << endl;
    cout << q.isEmpty() << endl;
    q.clear();
    cout << q.isEmpty() << endl;
}

void testBST()
{
    BST tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(3);
    tree.insert(9);
    tree.insert(10);
    tree.insert(6);
    tree.preorder();
    tree.inorder();
    tree.postorder();
    println(tree.findMax());
    println(tree.findMin());
    println(tree.find(6));
    println(tree.find(20));
}

int main() 
{
    //testStack();
    //testQueue();
    testBST();
    return 0;
}