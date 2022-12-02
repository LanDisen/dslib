#include <iostream>
#include "Stack.h"
#include "Queue.h"
//#include "BST.h"
#include "LinkedList.h"
#include "Algorithm.h"
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

// void testBST()
// {
//     BST tree;
//     tree.insert(5);
//     tree.insert(2);
//     tree.insert(8);
//     tree.insert(3);
//     tree.insert(9);
//     tree.insert(10);
//     tree.insert(6);
//     tree.preorder();
//     // tree.inorder();
//     // tree.postorder();
//     tree.remove(2);
//     tree.preorder();
//     tree.remove(5);
//     tree.preorder();
//     tree.remove(8);
//     tree.preorder();
// }

void testLinkedList()
{
    LinkedList ll;
    ll.insert(3);
    ll.insert(5);
    ll.insert(8);
    ll.insert(2);
    ll.insert(6);
    ll.insert(1);
    ll.insert(9);
    cout << ll.toString() << endl;
    cout << ll.getSize() << endl;
    cout << ll.contains(3) << endl;
    cout << ll.contains(10) << endl;
    cout << ll.remove(10) << endl;
    cout << ll.remove(3) << endl;
    cout << ll.toString() << endl;
    cout << ll.remove(1) << endl;
    cout << ll.remove(9) << endl;
    cout << ll.toString() << endl;
}

void testAlgorithm()
{
    int arr[10] = {2,5,1,8,6,4,3,7,9,0};
    int size = 10;
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, 2, 5);
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    //testStack();
    //testQueue();
    //testBST();
    //testLinkedList();
    testAlgorithm();
    cout << "end test" << endl;
    return 0;
}