#include <iostream>
#include <stdexcept>

using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 1000; // Maximum size of the queue
    int arr[MAX_SIZE];
    int front; // Index of the front element
    int rear; // Index of the rear element
    int itemCount; // Number of elements in the queue
public:
    // Constructor
    Queue() {
        front = 0; // Initializing front as 0
        rear = -1; // Initializing rear as -1 indicates an empty queue
        itemCount = 0; // Initializing item count as 0
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return itemCount == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return itemCount == MAX_SIZE;
    }

    // Function to add an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            throw overflow_error("Queue is full");
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        itemCount++;
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Function to remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        itemCount--;
        cout << "Dequeued " << value << " from the queue." << endl;
        return value;
    }

    // Function to return the front element of the queue
    int frontElement() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }

    // Function to return the rear element of the queue
    int rearElement() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[rear];
    }

    // Function to return the number of elements in the queue
    int size() {
        return itemCount;
    }
};

int main() {
    Queue queue;
    char choice;
    do {
        cout << "Choose an operation: " << endl;
        cout << "a) Enqueue" << endl;
        cout << "b) Dequeue" << endl;
        cout << "c) Front" << endl;
        cout << "d) Rear" << endl;
        cout << "e) Size" << endl;
        cout << "f) Empty" << endl;
        cout << "g) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                try {
                    queue.enqueue(value);
                } catch (const overflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 'b': {
                try {
                    queue.dequeue();
                } catch (const underflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 'c': {
                try {
                    cout << "Front element: " << queue.frontElement() << endl;
                } catch (const underflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 'd': {
                try {
                    cout << "Rear element: " << queue.rearElement() << endl;
                } catch (const underflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 'e': {
                cout << "Size of queue: " << queue.size() << endl;
                break;
            }
            case 'f': {
                cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << endl;
                break;
            }
            case 'g': {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 'g');

    return 0;
}

