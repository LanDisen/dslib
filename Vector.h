#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <string>

template<class E>
class Vector
{
public:
    Vector();
    Vector(int capacity);
    ~Vector();
    bool add(E e);
    bool add(E e, int index);
    bool remove();
    bool remove(int index);
    E get(int index);
    E getFirst();
    E getLast();
    bool isEmpty();
    int getSize();
    void clear();
    bool enlarge();
    bool enlarge(int capacity);

public:
    E *array = nullptr;
    int size = 0;
    int capacity = 0;
};

template<class E>
Vector<E>::Vector()
{
    size = 0;
    capacity = 10;
    array = new E[capacity];
}

template<class E>
Vector<E>::Vector(int capacity)
{
    array = new E[capacity];
}

template<class E>
Vector<E>::~Vector()
{
    delete[] array;
    size = 0;
    capacity = 0;
}

template<class E>
bool Vector<E>::add(E e)
{
    if (size >= capacity)
        enlarge();
    array[size++] = e;
    return true;
}

template<class E>
bool Vector<E>::add(E e, int index)
{
    if (index > size)
        return false;
    if (size >= capacity)
        enlarge();
    for (int i=size-1; i>=index; i--)
    {
        array[i+1] = array[i];
    }
    array[index] = e;
    size++;
    return true;
}

template <class E>
bool Vector<E>::remove()
{
    if (size == 0)
        return false;
    size--;
    return true;
}

template<class E>
bool Vector<E>::remove(int index)
{
    if (index >= size)
        return false;
    for (int i=index; i<size-1; i++)
        array[i] = array[i+1];
    size--;
    return true;
}

template<class E>
E Vector<E>::get(int index)
{
    return array[index];
}

template<class E>
E Vector<E>::getFirst()
{
    return array[0];
}

template<class E>
E Vector<E>::getLast()
{
    return array[size-1];
}

template<class E>
bool Vector<E>::isEmpty()
{
    if (size == 0)
        return true;
    return false;
}

template<class E>
int Vector<E>::getSize()
{
    return size;
}

template<class E>
void Vector<E>::clear()
{
    delete[] array;
    size = 0;
    capacity = 0;
}

template<class E>
bool Vector<E>::enlarge()
{
    E *temp = array;
    array = new E[capacity*2];
    for (int i=0; i<size; i++)
        array[i] = temp[i];
    delete[] temp;
    return true;
}

template<class E>
bool Vector<E>::enlarge(int capacity)
{
    if (capacity <= this->capacity)
        return false;
    E *temp = array;
    array = new E[capacity];
    for (int i=0; i<size; i++)
    {
        array[i] = temp[i];
    }
    delete[] temp;
}

#endif