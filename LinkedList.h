#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <string>

class Node {
public:
    Node();
    Node(int data);

public:
    int data;
    Node* prev;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool insert(int e);
    bool remove(int data);
    bool removeFirst();
    bool removeLast();
    bool contains(int data);
    int get(int index);
    bool isEmpty();
    int getSize();
    void clear();
    std::string toString();

public:
    Node* head;
    Node* rear;
    int size = 0;
};

Node::Node() {
    prev = nullptr;
    next = nullptr;
}

Node::Node(int data) {
    this->data = data;
    prev = nullptr;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
    rear = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

bool LinkedList::insert(int data) {
    if (head == nullptr) {
        head = new Node(data);
        rear = head;
        size++;
        return true;
    }
    if (data < head->data) {
        Node* node = new Node(data);
        node->next = head;
        head->prev = node;
        head = node;
        size++;
        return true;
    }
    Node* p = head;
    while (p != nullptr && data > p->data)
        p = p->next;
    if (p != nullptr) {
        if (data == p->data)
            return false;
        Node* node = new Node(data);
        node->prev = p->prev;
        node->next = p;
        p->prev->next = node;
        p->prev = node;
        size++;
        return true;
    }
    // p == nullptr
    rear->next = new Node(data);
    rear->next->prev = rear;
    rear = rear->next;
    size++;
    return true;
}

bool LinkedList::remove(int data) {
    if (data == head->data) {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        temp = nullptr;
        size--;
        return true;
    }
    if (data == rear->data) {
        Node* temp = rear;
        rear = rear->prev;
        rear->next = nullptr;
        delete temp;
        temp = nullptr;
        size--;
        return true;
    }
    Node* p = head->next;
    while (p != nullptr) {
        if (data == p->data) {
            Node* temp = p;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            delete temp;
            temp = nullptr;
            size--;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool LinkedList::removeFirst() {
    if (head == nullptr)
        return false;
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    temp = nullptr;
    size--;
    return true;
}

bool LinkedList::removeLast() {
    if (rear == nullptr)
        return false;
    Node* temp = rear;
    rear = rear->prev;
    head->next = nullptr;
    delete temp;
    temp = nullptr;
    size--;
    return true;
}

bool LinkedList::contains(int data) {
    if (isEmpty())
        return false;
    Node* p = head;
    while (p != nullptr) {
        if (data == p->data)
            return true;
        p = p->next;
    }
    return false;
}

int LinkedList::get(int index) {
    int i = 0;
    Node* p = head;
    while (i++ < index)
        p = p->next;
    return p->data;
}

bool LinkedList::isEmpty() {
    if (size == 0)
        return true;
    return false;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::clear() {
    if (isEmpty())
        return;
    Node* p = head;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
        temp = nullptr;
    }
    head = nullptr;
    rear = nullptr;
    size = 0;
}

std::string LinkedList::toString() {
    std::string str = "";
    Node* p = head;
    while (p != nullptr) {
        int data = p->data;
        p = p->next;
        if (data == 0) {
            str += '0';
            if (p != nullptr)
                str += ' ';
            continue;
        }
        std::string s = "";
        if (data < 0) {
            s += '-';
            data *= -1;
        }
        while (data != 0) {
            s += data % 10 + '0';
            data /= 10;
        }
        for (int i = s.size() - 1; i >= 0; i--)
            str += s[i];
        if (p != nullptr)
            str += ' ';
    }
    return str;
}

#endif