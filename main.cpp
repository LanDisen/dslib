#include <iostream>
#include "Queue.h"
#include "Stack.h"
// #include "BST.h"
#include "Algorithm.h"
#include "Array.h"
#include "LinkedList.h"
#include "List.h"
using namespace std;

template <typename T>
void print(T t) {
    cout << t;
}

template <typename T>
void println(T t) {
    cout << t << endl;
}

// void testStack() {
//     Stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     cout << s.top() << endl;
//     s.pop();
//     cout << s.top() << endl;
//     s.pop();
//     cout << s.isEmpty() << endl;
//     cout << s.top() << endl;
//     s.pop();
//     cout << s.isEmpty() << endl;
// }

// void testQueue() {
//     Queue<int> q;
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     cout << q.front() << endl;
//     cout << q.rear() << endl;
//     q.dequeue();
//     cout << q.front() << endl;
//     q.enqueue(40);
//     cout << q.rear() << endl;
//     cout << q.isEmpty() << endl;
//     q.clear();
//     cout << q.isEmpty() << endl;
// }

// void testBST() {
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

void testLinkedList() {
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

void testAlgorithm() {
    int arr[10] = {2, 5, 1, 8, 6, 4, 3, 7, 9, 0};
    int size = 10;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, 2, 5);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testList() {
    List<int> l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    for (int i = 0; i < l.size; i++)
        cout << l.array[i] << ' ';
    cout << endl;
    l.add(10, 3);
    l.remove(0);
    for (int i = 0; i < l.size; i++)
        cout << l.array[i] << ' ';
    cout << endl;
    l.add(6);
    l.add(7, 6);
    l.add(8, 6);
    for (int i = 0; i < l.size; i++)
        cout << l.get(i) << ' ';
    cout << endl;
    cout << l.getSize() << endl;
    l.clear();
    cout << l.getSize() << endl;
    cout << l.isEmpty() << endl;
    for (int i = 0; i < l.size; i++)
        cout << l.get(i) << ' ';
    cout << endl;
}

void testArray() {
    // Array<int> a;
    // for (int i = 0; i < 10; i++)
    //     a.set(i, i);
    // for (int i = 0; i < 10; i++) {
    //     cout << a.get(i) << " ";
    // }
    // cout << endl;
    // a.set(200, 200);
    // cout << a.get(200) << endl;
    // cout << a.size << endl;
    int a[] = {0,1,2,3,4};
    Array<int> a1(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;
    Array<Array<int>> a2(5);
    a2[0] = a1;
    for (int i = 0; i < 3; i++) {
        cout << a2[0][i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "<Test Start>" << endl;
    // testStack();
    // testQueue();
    // testBST();
    // testLinkedList();
    // testAlgorithm();
    // testList();
    testArray();
    cout << "<Test End>" << endl;
    return 0;
}