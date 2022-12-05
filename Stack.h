template <class T>
class Stack {
public:
    void push(T e) {
        array[size++] = e;
    }

    void pop() {
        size--;
    }

    T top() {
        return array[size - 1];
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
    }

private:
    T array[100];
    int size = 0;
};