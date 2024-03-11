class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Stack {
    Node head;
    int size;
    Stack() {
        head = null;
        size = 0;
    }

    void push(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
        size++;
    }

    int pop() {
        if (head == null) {
            return -1;
        }
        int data = head.data;
        head = head.next;
        size--;
        return data;
    }

    int peek() {
        if (head == null) {
            return -1;
        }
        return head.data;
    }

    boolean isEmpty() {
        return head == null;
    }

    int size() {
        return size;
    }
}

public class implementStackUsingLinkedList {
    
}
