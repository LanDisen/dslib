template<class T>
class Stack
{
public:
    Stack() {}

    Stack(int size)
    {
        array = new T(size);
    }

    void pop()
    {
        size--;
    }

    void push(T e)
    {
        array[size++] = e;
    }

    T top()
    {
        return array[size-1];
    }

    bool isEmpty()
    {
        if (size <= 0)
            return true;
        return false;
    }

private:
    T array[100];
    int size = 0;
};