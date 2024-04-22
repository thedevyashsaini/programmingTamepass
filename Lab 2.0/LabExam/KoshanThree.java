class Node<T> {
    T data;
    Node<T> next;

    Node(T item) {
        this.data = item;
        this.next = null;
    }
}

class LinkedList<T> {
    int size;
    Node<T> head;

    LinkedList() {
        size = 0;
        head = null;
    }

    void insertHead(T data) {
        if(head == null) {
            Node<T> temp = new Node<T>(data);
            head = temp;
        }
        else {
            Node<T> temp = new Node<T>(data);
            temp.next = head;
            head = temp;
        }
        size++;
    }

    void removeHead() {
        if (size >= 1) {
            head = head.next;
            size--;
        }
    }

    T getHead() {
        return head.data;
    }

    int getSize() {
        return size;
    }

    boolean isEmpty() {
        return size == 0;
    }
}

class Stack<T> {
    LinkedList<T> stack;

    Stack() {
        stack = new LinkedList<T>();
    }

    void push(T data) {
        stack.insertHead(data);
    }

    T pop() {
        T temp = stack.getHead();
        stack.removeHead();
        return temp;
    }

    T peek() {
        return stack.getHead();
    }

    int getSize() {
        return stack.getSize();
    }

    boolean isEmpty() {
        return stack.isEmpty();
    }

    void print() {
        Node<T> temp = stack.head;
        for (int i = 0; i < stack.getSize(); i++) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}

class Queue<T> {
    Stack<T> stack1; // for enqueue
    Stack<T> stack2; // for dequeue

    Queue() {
        stack1 = new Stack<T>();
        stack2 = new Stack<T>();
    }

    void enqueue(T data) {
        stack1.push(data);
    }

    void pour() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
    }

    T dequeue() {
        if (!stack2.isEmpty()) {
            return stack2.pop();
        } else {
            pour();
            return dequeue();
        }
    }

    T getFront() {
        if (!stack2.isEmpty()) {
            return stack2.peek();
        } else {
            pour();
            return getFront();
        }
    }

    int getSize() {
        return stack1.getSize() + stack2.getSize();
    }

    boolean isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    void print() {
        if (this.getSize() == 0) {
            System.out.println("Null");
            return;
        }
        stack2.print();
        Stack<T> temp = new Stack<T>();
        while (!stack1.isEmpty()) {
            temp.push(stack1.pop());
        }
        temp.print();
        System.out.println();
        while (!temp.isEmpty()) {
            stack1.push(temp.pop());
        }
        temp = null;
    }
}

public class KoshanThree {
    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<Integer>();
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        System.out.print("Queue: ");
        queue.print();
        System.out.println("Size: " + queue.getSize());
        System.out.println("isEmpty: " + queue.isEmpty());
        System.out.println(queue.getFront());
        System.out.println(queue.getFront());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.getFront());
        System.out.print("Queue: ");
        queue.print();
        System.out.println("Size: " + queue.getSize());
        System.out.println("isEmpty: " + queue.isEmpty());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.print("Queue: ");
        queue.print();
        System.out.println("Size: " + queue.getSize());
        System.out.println("isEmpty: " + queue.isEmpty());
    }
}