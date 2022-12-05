#ifndef _ARRAY_H_
#define _ARRAY_H_

template <class E>
class Array {
public:
    Array();
    Array(int size);
    Array(E *a, int size);
    ~Array();
    void set(E e, int index);
    E get(int index);
    void resize(int size);
    E& operator[](int index);
    Array<E>& operator=(const Array<E>& array);

public:
    E* arr;
    int size;
};

template <class E>
Array<E>::Array() {
    arr = new E[100];
    size = 100;
}

template <class E>
Array<E>::Array(E *a, int size) {
    this->size = size;
    arr = new E[size];
    for (int i=0; i<size; i++) {
        arr[i] = a[i];
    }
}

template <class E>
Array<E>::Array(int size) {
    arr = new E[size];
    this->size = size;
}

template <class E>
Array<E>::~Array() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

template <class E>
void Array<E>::set(E e, int index) {
    if (index >= size)
        resize(index * 2);
    arr[index] = e;
}

template <class E>
E Array<E>::get(int index) {
    return arr[index];
}

template <class E>
void Array<E>::resize(int size) {
    if (size <= this->size)
        return;
    E* newarr = new E[size];
    for (int i = 0; i < this->size; i++) {
        newarr[i] = arr[i];
    }
    this->size = size;
    E* temp = arr;
    arr = newarr;
    delete temp;
    temp = nullptr;
}

template <class E>
E& Array<E>::operator[](int index) {
    return arr[index];
}

template <class E>
Array<E>& Array<E>::operator=(const Array<E>& array) {
    this->arr = array.arr;
    this->size = array.size;
    return *this;
}

#endif