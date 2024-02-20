#include  <bits/stdc++.h>

using namespace std;

template <typename T> class Vector {
    
private:
    T* arr;
    int capacity;
    int size;

    void increasegetSize() {
        // Increase the capacity of the array by 2 times
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
        delete[] temp;
    }

public:
    Vector() {
        capacity = 8;
        size = 0;
        arr = new T[capacity];
    }

    Vector(int cap) {
        capacity = cap;
        size = 0;
        arr = new T[capacity];
    }

    void add(T item) {
        // add item to the end of the array
        if (size == capacity) {
            increasegetSize();
        }
        arr[size++] = item;
    }

    void add(int index, T item) {
        // add item at the given index
        if (index >= size) {
            size = index+1;
        } else {
            throw "Illegal Access Error";
        }
        while (size >= capacity) {
            increasegetSize();
        }
        arr[index] = item;
    }
    void push(T item) {
        // add item at the beginning of the array
        if (size == capacity) {
            increasegetSize();
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        set(0, item);
        size++;
    }

    void remove(int index) {
        // remove item at the given index
        if (index < 0 || index >= size) {
            throw "Illegal Access Error";
        }
        for (int i = index; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void pop() {
        // remove item from the end of the array
        if (size == 0) {
            throw "Illegal Access Error";
        }
        size--;
    }

    void shiftBack() {
        // remove item from the beginning of the array
        if (size == 0) {
            throw "Illegal Access Error";
        }
        for (int i = 0; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void removeItem(T item) {
        // remove the first occurrence of the item from the array
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                remove(i);
                return;
            }
        }
        throw "Item not found";
    }

    T get(int index) {
        // get item at the given index
        if (index < 0 || index >= size) {
            throw "Illegal Access Error";
        }
        return (T) arr[index];
    }

    void set(int index, T item) {
        // set item at the given index
        if (index < 0 || index >= size) {
            throw "Illegal Access Error";
        }
        arr[index] = item;
    }

    int indexOf(T item) {
        // get the index of the first occurrence of the item
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }

    bool contains(T item) {
        // check if the item is present in the array
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        // check if the array is empty
        return size == 0;
    }

    void clear() {
        // clear the array
        size = 0;
    }

    int getSize() {
        // get the size of the array
        return size;
    }

    int getCapacity() {
        // get the capacity of the array
        return capacity;
    }
};

template <typename T>
void printArray(Vector<T> arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;
}

int main() {
        Vector<int> arr;
        for (int i = 0; i < 12; i++) {
            arr.add(i);
            cout<<arr.get(i)<<endl;
        }
        printArray(arr);
        cout<<arr.getSize()<<endl;
        arr.add(13, 100);
        cout<<"Size: " << arr.getSize() << endl;
        cout<<"Capacity: " << arr.getCapacity() << endl;
        arr.push(100);
        arr.remove(2);
        printArray(arr);
        arr.pop();
        arr.shiftBack();
        arr.removeItem(8);
        arr.set(2, 1000);
        printArray(arr);
        cout<<"Item at index 2: " << arr.get(2) << endl;
        if (arr.contains(1000)) {
            cout<<"1000 is present at index: " << arr.indexOf(1000) << endl;
        }
        cout<<"Size: " << arr.getSize() << endl;
        cout<<"Capacity: " << arr.getCapacity() << endl;
        cout<<"Is empty: " << arr.isEmpty() << endl;
        arr.clear();
        cout<<"Size: " << arr.getSize() << endl;
        cout<<"Is empty: " << arr.isEmpty() << endl;
    return 0;
}