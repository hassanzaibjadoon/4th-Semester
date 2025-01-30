#include <iostream>
using namespace std;
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    // Constructor
    Node(int value) : data(value), next(NULL) {}
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack
    int itemCount; // Number of elements in the stack

public:
    // Constructor
    Stack() : top(NULL), itemCount(0) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return itemCount == 0;
    }
    // Function to add an element to the top of the stack (push)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        itemCount++;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Function to remove the element from the top of the stack (pop)
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Unable to pop." << endl;
            return -1; // Returning a default value
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        itemCount--;
        cout << "Popped " << value << " from the stack." << endl;
        return value;
    }

    // Function to return the top element of the stack
    int topElement() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Returning a default value
        }
        return top->data;
    }

    // Function to return the size of the stack
    int size() {
        return itemCount;
    }
};

int main() {
    Stack stack;
    char choice;

    do {
        cout << "\nChoose an operation: " << endl;
        cout << "a) Push" << endl;
        cout << "b) Pop" << endl;
        cout << "c) Top" << endl;
        cout << "d) Size" << endl;
        cout << "e) Empty" << endl;
        cout << "f) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 'b': {
                stack.pop();
                break;
            }
            case 'c': {
                cout << "Top element: " << stack.topElement() << endl;
                break;
            }
            case 'd': {
                cout << "Size of stack: " << stack.size() << endl;
                break;
            }
            case 'e': {
                cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << endl;
                break;
            }
            case 'f': {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 'f');

    return 0;
}

