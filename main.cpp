#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

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

int main() 
{
    //testStack();
    testQueue();
    return 0;
}