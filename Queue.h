#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class T>
class Queue {
public:
    void enqueue(T e) {
        size++;
        array[++rearPos] = e;
    }

    void dequeue() {
        size--;
        frontPos++;
    }

    T front() {
        return array[frontPos];
    }

    T rear() {
        return array[rearPos];
    }

    bool isEmpty() {
        if (size <= 0)
            return true;
        return false;
    }

    int getSize() {
        return size;
    }

    void clear() {
        size = 0;
        frontPos = 0;
        rearPos = -1;
    }

private:
    T array[100];
    int size = 0;
    int frontPos = 0;
    int rearPos = -1;
};

#endif