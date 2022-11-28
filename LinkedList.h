template<class T>
class Node
{
public:
    Node() 
    {
        val = default;
        last = nullptr;
        next = nullptr;
    }

    T val;
    Node *last;
    Node *next;
};

template<class T>
class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        rear = nullptr;
        size = 0;
    }

    void insert()
    {

    }

    void remove()
    {
        
    }

    void first()
    {

    }


    Node<T> *head;
    Node<T> *rear;
    int size;
};