import java.util.Arrays;

class ArrayList<T> {
    Object[] arr;
    int size;
    int capacity;

    ArrayList() {
        capacity = 8;
        size = 0;
        arr = new Object[capacity];
    }

    ArrayList(int cap) {
        capacity = cap;
        size = 0;
        arr = new Object[capacity];
    }

    void increaseSize() {
        // Doubles the size of the array
        capacity *= 2;
        Object[] tempArr = new Object[capacity];
        for (int i = 0; i < size; i++) {
            tempArr[i] = arr[i];
        }
        arr = tempArr;
        tempArr = null;
    }

    void add(T item) {
        // Adds an item to the end of the array
        if (size == capacity) {
            increaseSize();
        }
        arr[size++] = item;
    }

    void add(int index, T item) {
        // Adds an item at the specified index
        if (index >= size) {
            size = index+1;
        } else {
            throw new IllegalAccessError();
        }
        while (size >= capacity) {
            increaseSize();
        }
        arr[index] = item;
    }

    void push(T item) {
        // Adds an item to the beginning of the array
        if (size == capacity) {
            increaseSize();
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        set(0, item);
        size++;
    }

    void remove(int index) {
        // Removes an item at the specified index
        if(index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void pop() {
        // Removes an item from the end of the array
        if (size == 0) {
            throw new IndexOutOfBoundsException();
        }
        size--;
    }

    void shiftBack() {
        // Removes an item from the beginning of the array
        if (size == 0) {
            throw new IndexOutOfBoundsException();
        }
        remove(0);
    }

    void removeItem(T item) {
        // Removes the first occurrence of the item from the array
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                remove(i);
                return;
            }
        }
        throw new IllegalArgumentException();
    }

    T get(int index) {
        // Returns the item at the specified index
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        return (T) arr[index];
    }

    int indexOf(T item) {
        // Returns the index of the first occurrence of the item
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }

    boolean contains(T item) {
        // Returns true if the item is present in the array
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return true;
            }
        }
        return false;
    }

    void set(int index, T item) {
        // Sets the item at the specified index
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
        arr[index] = item;
    }

    boolean isEmpty() {
        // Returns true if the array is empty
        return size == 0;
    }

    void clear() {
        // Clears the array
        size = 0;
    }

    void sort() {
        // Sorts the array
        Arrays.sort(arr);
    }
}

public class ImplementArrayList {
    static void printArray(ArrayList<Integer> arr) {
        System.out.print("Array:");
        for (int i = 0; i < arr.size; i++) {
            System.out.print(" " + arr.get(i));
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for (int i = 0; i < 12; i++) {
            arr.add(i);
        }
        printArray(arr);
        arr.add(13, 100);
        System.out.println("Size: " + arr.size);
        System.out.println("Capacity: " + arr.capacity);
        arr.push(100);
        arr.remove(2);
        printArray(arr);
        arr.pop();
        arr.shiftBack();
        arr.removeItem(8);
        arr.set(2, 1000);
        printArray(arr);
        System.out.println("Item at index 2: " + arr.get(2));
        if (arr.contains(1000)) {
            System.out.println("1000 is present at index: " + arr.indexOf(1000));
        }
        System.out.println("Size: " + arr.size);
        System.out.println("Capacity: " + arr.capacity);
        System.out.println("Is empty: " + arr.isEmpty());
        arr.sort();
        printArray(arr);
        arr.clear();
        System.out.println("Size: " + arr.size);
        System.out.println("Is empty: " + arr.isEmpty());
    }
}