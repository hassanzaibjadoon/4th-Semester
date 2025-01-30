#include <iostream>

using namespace std;
//task03 lab09
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear; // Pointer to the rear of the queue
    int itemCount; // Number of elements in the queue

public:
    // Constructor
    Queue() : front(NULL), rear(NULL), itemCount(0) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return itemCount == 0;
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        itemCount++;
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Function to remove an element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to dequeue." << endl;
            return -1; // Returning a default value
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        itemCount--;
        cout << "Dequeued " << value << " from the queue." << endl;
        return value;
    }

    // Function to return the front element of the queue
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Returning a default value
        }
        return front->data;
    }

    // Function to return the rear element of the queue
    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty. No rear element." << endl;
            return -1; // Returning a default value
        }
        return rear->data;
    }

    // Function to return the size of the queue
    int size() {
        return itemCount;
    }
};

int main() {
    Queue queue;
    char choice;

    do {
        cout << "\nChoose an operation: " << endl;
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
                queue.enqueue(value);
                break;
            }
            case 'b': {
                queue.dequeue();
                break;
            }
            case 'c': {
                cout << "Front element: " << queue.frontElement() << endl;
                break;
            }
            case 'd': {
                cout << "Rear element: " << queue.rearElement() << endl;
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

