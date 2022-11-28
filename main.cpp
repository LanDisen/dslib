#include <iostream>
#include "Stack.h"
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

int main() 
{
    testStack();
    return 0;
}