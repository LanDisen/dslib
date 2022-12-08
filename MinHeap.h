#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

class MinHeap {
public:
    MinHeap(int n) {
        array = new int[n];
        array[0] = -2147483628;
        size = 0;
    }

    ~MinHeap() {
        delete[] array;
        array = nullptr;
        size = 0;
    }

    void push(int data) {
        array[++size] = data;
        int i = size;
        while (i > 0) {
            if (array[i] < array[i/2]) {
                int t = array[i];
                array[i] = array[i/2];
                array[i/2] = t;
                i /= 2;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (isEmpty()) return;
        int t = array[1];
        array[1] = array[size];
        array[size] = t;
        size--;
        int i = 1;
        while (i <= size/2) {
            int j;
            if (array[i*2] < array[i*2+1]) {
                j = i * 2;
            } else {
                j = i * 2 + 1;
            }
            if (array[i] > array[j]) {
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
                i = j;
            } else {
                break;
            }
        }
    }

    int get() {
        return array[1];
    }

    bool isEmpty() {
        if (size == 0)
            return true;
        return false;
    }

public:
    int* array = nullptr;
    int size = 0;
};

#endif