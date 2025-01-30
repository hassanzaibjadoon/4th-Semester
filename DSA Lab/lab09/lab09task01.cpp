#include <iostream>
#include <stdexcept>
//lab09 task1
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 1000; // Maximum size of the stack
    int arr[MAX_SIZE];
    int top; // Index of the top element in the stack
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int value) {
        if (isFull()) {
            throw overflow_error("Stack is full");
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        int value = arr[top--];
        cout << "Popped " << value << " from the stack." << endl;
        return value;
    }

    // Function to return the top element of the stack
    int topElement() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }

    // Function to return the size of the stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack;
    char choice;

    do {
        cout << "Choose an operation: " << endl;
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
                try {
                    stack.push(value);
                } catch (const overflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 'b': {
                try {
                    stack.pop();
                } catch (const underflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 'c': {
                try {
                    cout << "Top element: " << stack.topElement() << endl;
                } catch (const underflow_error &e) {
                    cerr << "Error: " << e.what() << endl;
                }
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


