import java.util.*;

class MinHeap{
    int[] heap;
    int size;
    int maxSize;

    MinHeap(int maxSize){
        this.maxSize = maxSize;
        this.size = 0;
        heap = new int[this.maxSize + 1];
        heap[0] = Integer.MIN_VALUE;
    }

    int parent(int pos){
        return pos/2;
    }

    int leftChild(int pos){
        return 2*pos;
    }

    int rightChild(int pos){
        return 2*pos + 1;
    }

    boolean isLeaf(int pos){
        if(pos >= (size/2) && pos <= size){
            return true;
        }
        return false;
    }

    void swap(int fpos, int spos){
        int temp;
        temp = heap[fpos];
        heap[fpos] = heap[spos];
        heap[spos] = temp;
    }

    void minHeapify(int pos){
        if(!isLeaf(pos)){
            if(heap[pos] > heap[leftChild(pos)] || heap[pos] > heap[rightChild(pos)]){
                if(heap[leftChild(pos)] < heap[rightChild(pos)]){
                    swap(pos, leftChild(pos));
                    minHeapify(leftChild(pos));
                }
                else{
                    swap(pos, rightChild(pos));
                    minHeapify(rightChild(pos));
                }
            }
        }
    }

    void insert(int element){
        heap[++size] = element;
        int current = size;
        while(heap[current] < heap[parent(current)]){
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void print(){
        for(int i = 1; i <= size/2; i++){
            System.out.print("Parent: " + heap[i] + " Left Child: " + heap[2*i] + " Right Child: " + heap[2*i + 1]);
            System.out.println();
        }
    }

    int remove(){
        int popped = heap[1];
        heap[1] = heap[size--];
        minHeapify(1);
        return popped;
    }
}

public class ImplementMinHeaps {
    public static void main(String[] args) {
        MinHeap minHeap = new MinHeap(15);
        minHeap.insert(5);
        minHeap.insert(3);
        minHeap.insert(17);
        minHeap.insert(10);
        minHeap.insert(84);
        minHeap.insert(19);
        minHeap.insert(6);
        minHeap.insert(22);
        minHeap.insert(9);
        minHeap.print();
        System.out.println("The Min val is " + minHeap.remove());
    }  
}