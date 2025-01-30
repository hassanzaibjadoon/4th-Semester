#include <iostream>
using namespace std;

class ArrayList {
private:
    int* list;
    int size;
    int capacity;

public:
    // Constructor with initial capacity
    ArrayList(int initialCapacity = 10) {
        list = new int[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    // Destructor to free memory
    ~ArrayList() {
        delete[] list;
    }

    // Add item at a specific index
    void add(int item, int index) {
        if (index < 0 || index > size) {
            cout << "Error: Index out of bounds." << endl;
            return;
        }

        if (size == capacity) {
            resize();
        }

        for (int i = size; i > index; i--) {
            list[i] = list[i - 1]; // Shift elements to the right
        }

        list[index] = item;
        size++;
    }

    // Remove item from a specific index
    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds." << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            list[i] = list[i + 1]; // Shift elements to the left
        }

        size--;
    }

    // Get current size of the list
    int getSize() {
        return size;
    }

    // Check if the list is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get an element at a specific index
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds." << endl;
            return -1;
        }
        return list[index];
    }

    // Get the last element in the list
    int End() {
        if (isEmpty()) {
            cout << "Error: List is empty." << endl;
            return -1;
        }
        return list[size - 1];
    }

    // Get the first element in the list
    int Start() {
        if (isEmpty()) {
            cout << "Error: List is empty." << endl;
            return -1;
        }
        return list[0];
    }

private:
    // Resize the list when capacity is full
    void resize() {
        int newCapacity = capacity * 2;
        int* newList = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newList[i] = list[i]; // Copy elements to new list
        }

        delete[] list;
        list = newList;
        capacity = newCapacity;
    }
};

int main() {
    ArrayList list;
    char choice;
    int index, item;

    do {
        cout << "\n====== ArrayList Menu ======\n";
        cout << "1. Add an item\n";
        cout << "2. Remove an item\n";
        cout << "3. Get size of the list\n";
        cout << "4. Check if the list is empty\n";
        cout << "5. Get an item by index\n";
        cout << "6. Get last element (End)\n";
        cout << "7. Get first element (Start)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                cout << "Enter index and item to add: ";
                cin >> index >> item;
                list.add(item, index);
                break;
            case '2':
                cout << "Enter index to remove: ";
                cin >> index;
                list.remove(index);
                break;
            case '3':
                cout << "Size of the list: " << list.getSize() << endl;
                break;
            case '4':
                cout << (list.isEmpty() ? "The list is empty." : "The list is not empty.") << endl;
                break;
            case '5':
                cout << "Enter index to retrieve item: ";
                cin >> index;
                cout << "Item at index " << index << ": " << list.get(index) << endl;
                break;
            case '6':
                cout << "Last element: " << list.End() << endl;
                break;
            case '7':
                cout << "First element: " << list.Start() << endl;
                break;
            case '8':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while(choice != '8');

    return 0;
}
