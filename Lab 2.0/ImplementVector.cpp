#include  <bits/stdc++.h>

using namespace std;

template <typename T> class Vector {
    T* arr;
public:
    int capacity;
    int size;
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
        if (size == capacity) {
            increaseSize();
        }
        arr[size++] = item;
    }

    void add(int index, T item) {
        if (index >= size) {
            size = index+1;
        } else {
            throw "Illegal Access Error";
        }
        while (size >= capacity) {
            increaseSize();
        }
        arr[index] = item;
    }
    void push(T item) {
        if (size == capacity) {
            increaseSize();
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        set(0, item);
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw "Illegal Access Error";
        }
        for (int i = index; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void pop() {
        if (size == 0) {
            throw "Illegal Access Error";
        }
        size--;
    }

    void shiftBack() {
        if (size == 0) {
            throw "Illegal Access Error";
        }
        for (int i = 0; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void removeItem(T item) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                remove(i);
                return;
            }
        }
        throw "Item not found";
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw "Illegal Access Error";
        }
        return (T) arr[index];
    }

    void set(int index, T item) {
        if (index < 0 || index >= size) {
            throw "Illegal Access Error";
        }
        arr[index] = item;
    }

    int indexOf(T item) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }

    bool contains(T item) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        return size == 0;
    }

    void clear() {
        size = 0;
    }

    void sort() {
        sort(arr, arr+size);
    }
private:
    increaseSize() {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
        delete[] temp;
    }
};

void printArray(Vector<int> arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << arr.get(i) << " ";
    }
    cout << endl;
}

int main() {
        Vector<int> arr = Vector<int>();
        for (int i = 0; i < 12; i++) {
            arr.add(i);
        }
        printArray(arr);
        arr.add(13, 100);
        cout<<"Size: " << arr.size << endl;
        cout<<"Capacity: " << arr.capacity << endl;
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
        cout<<"Size: " << arr.size << endl;
        cout<<"Capacity: " << arr.capacity << endl;
        cout<<"Is empty: " << arr.isEmpty() << endl;
        arr.sort();
        printArray(arr);
        arr.clear();
        cout<<"Size: " << arr.size << endl;
        cout<<"Is empty: " << arr.isEmpty() << endl;
    return 0;
}