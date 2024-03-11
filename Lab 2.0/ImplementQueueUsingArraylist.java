class Queue<T> {
    Object[] arr;
    int front;
    int rear;
    int capacity;

    Queue() {
        capacity = 8;
        arr = new Object[capacity];
        front = -1;
        rear = -1;
    }

    Queue(int cap) {
        capacity = cap;
        arr = new Object[capacity];
        front = -1;
        rear = -1;
    }

    void increaseSize() {
        capacity *= 2;
        Object[] tempArr = new Object[capacity];
        for (int i = 0; i <= rear; i++) {
            tempArr[i] = arr[i];
        }
        arr = tempArr;
        tempArr = null;
    }

    void push(T item) {
        if (rear+1 == capacity) {
            increaseSize();
        }
        arr[++rear] = item;
        if (front == -1) {
            front++;
        }
    }

    @SuppressWarnings("unchecked")
    T pop() {
        if (front == -1) {
            return null;
        }
        T data = (T) arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return data;
    }

    @SuppressWarnings("unchecked")
    T peek() {
        if (front == -1) {
            return null;
        }
        return (T) arr[front];
    }

    boolean isEmpty() {
        return front == -1;
    }

    int size() {
        if (front == -1) {
            return 0;
        }
        return rear-front+1;
    }

    void print() {
        for (int i = front; i <= rear; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

public class ImplementQueueUsingArraylist {
    public static void main(String[] args) {
        Queue<Integer> q = new Queue<>();
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        q.push(7);
        q.push(8);
        q.push(9);
        q.push(10);
        q.print();
        System.out.println(q.pop());
        System.out.println(q.pop());
        System.out.println(q.peek());
        System.out.println(q.size());
    }
}
