class Stack<T> {
    Object[] arr;
    int top;
    int capacity;

    Stack() {
        capacity = 8;
        arr = new Object[capacity];
        top = -1;
    }

    Stack(int cap) {
        capacity = cap;
        arr = new Object[capacity];
        top = -1;
    }

    void increaseSize() {
        capacity *= 2;
        Object[] tempArr = new Object[capacity];
        for (int i = 0; i <= top; i++) {
            tempArr[i] = arr[i];
        }
        arr = tempArr;
        tempArr = null;
    }

    void push(T item) {
        if (top+1 == capacity) {
            increaseSize();
        }
        arr[top++] = item;
    }

    @SuppressWarnings("unchecked")
    T pop() {
        if (top == -1) {
            return null;
        }
        return (T) arr[top--];
    }

    @SuppressWarnings("unchecked")
    T peek() {
        if (top == -1) {
            return null;
        }
        return (T) arr[top];
    }

    boolean isEmpty() {
        return top == -1;
    }

    int size() {
        return top+1;
    }
}

public class ImplementStack {
    
}
