#include <iostream>
using namespace std;
//lab 08 task03
// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Class for doubly linked list
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert data at the start of the list (preappend)
    void insertAtStart(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted " << data << " at the start of the list." << endl;
    }

    // Function to insert data at the end of the list (append)
    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            cout << "Appended " << data << " to the end of the list." << endl;
            return;
        }
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        cout << "Appended " << data << " to the end of the list." << endl;
    }

    // Function to insert data at nth location in the list
    void insertAtNth(int data, int n) {
        if (n < 1) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        if (n == 1) {
            insertAtStart(data);
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        Node* current = head;
        for (int i = 1; i < n - 1 && current != NULL; ++i) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
            cout << "Inserted " << data << " at position " << n << " in the list." << endl;
        }
    }

    // Function to delete the first node of the list
    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cout << "Deleted first node from the list." << endl;
    }

    // Function to delete the last node of the list
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted last node from the list." << endl;
            return;
        }
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->prev->next = NULL;
        delete last;
        cout << "Deleted last node from the list." << endl;
    }

    // Function to delete node from nth position in the list
    void deleteFromNth(int n) {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (n < 1) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        if (n == 1) {
            deleteFromStart();
            return;
        }
        Node* current = head;
        for (int i = 1; i < n && current != NULL; ++i) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            delete current;
            cout << "Deleted node at position " << n << " from the list." << endl;
        }
    }

    // Function to search for a key in the list
    bool search(int key) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to update data of a node at nth position in the list
    void update(int data, int n) {
        if (n < 1) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        Node* current = head;
        for (int i = 1; i < n && current != NULL; ++i) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            current->data = data;
            cout << "Updated data at position " << n << " in the list." << endl;
        }
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == NULL;
    }

    // Function to calculate the size of the list
    int size() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to print the list forward
    void printListForward() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Doubly Linked List (forward): ";
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to print the list backward
    void printListBackward() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Doubly Linked List (backward): ";
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        while (current != NULL) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    int choice, data, position;

    do {
        cout << "\n1. Insert at start\n2. Insert at end\n3. Insert at nth position\n4. Delete from start\n5. Delete from end\n6. Delete from nth position\n";
        cout << "7. Search for a key\n8. Update list\n9. Empty list\n10. Calculate size\n11. Print list forward\n12. Print list backward\n13. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at start: ";
                cin >> data;
                list.insertAtStart(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtNth(data, position);
                break;
            case 4:
                list.deleteFromStart();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.deleteFromNth(position);
                break;
            case 7:
                cout << "Enter key to search for: ";
                cin >> data;
                if (list.search(data)) {
                    cout << "Key found in the list." << endl;
                } else {
                    cout << "Key not found in the list." << endl;
                }
                break;
            case 8:
                cout << "Enter data to update: ";
                cin >> data;
                cout << "Enter position to update at: ";
                cin >> position;
                list.update(data, position);
                break;
            case 9:
                if (list.isEmpty()) {
                    cout << "List is empty." << endl;
                } else {
                    cout << "List is not empty." << endl;
                }
                break;
            case 10:
                cout << "Size of the list: " << list.size() << endl;
                break;
            case 11:
                list.printListForward();
                break;
            case 12:
                list.printListBackward();
                break;
            case 13:
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 13);

    return 0;
}






//task04
/*#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Class for circular linked list
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = NULL;
    }

    // Function to insert data at the start of the list (preappend)
    void insertAtStart(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << data << " at the start of the list." << endl;
    }

    // Function to insert data at the end of the list (append)
    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Appended " << data << " to the end of the list." << endl;
    }

    // Function to insert data at nth location in the list
    void insertAtNth(int data, int n) {
        if (n < 1) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        if (n == 1) {
            insertAtStart(data);
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        Node* current = head;
        for (int i = 1; i < n - 1 && current != NULL; ++i) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            newNode->next = current->next;
            current->next = newNode;
            cout << "Inserted " << data << " at position " << n << " in the list." << endl;
        }
    }

    // Function to delete the first node of the list
    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Deleted first node from the list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        cout << "Deleted first node from the list." << endl;
    }

    // Function to delete the last node of the list
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Deleted last node from the list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
        cout << "Deleted last node from the list." << endl;
    }

    // Function to delete node from nth position in the list
    void deleteFromNth(int n) {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (n < 1) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        if (n == 1) {
            deleteFromStart();
            return;
        }
        Node* current = head;
        for (int i = 1; i < n - 1 && current != NULL; ++i) {
            current = current->next;
        }
        if (current == NULL || current->next == head) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Deleted node at position " << n << " from the list." << endl;
        }
    }

    // Function to search for a key in the list
    bool search(int key) {
        if (head == NULL) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Function to update data of a node at nth position in the list
    void update(int data, int n) {
        if (n < 1) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        Node* current = head;
        for (int i = 1; i < n && current != NULL; ++i) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            current->data = data;
            cout << "Updated data at position " << n << " in the list." << endl;
        }
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == NULL;
    }

    // Function to calculate the size of the list
    int size() {
        int count = 0;
        Node* temp = head;
        if (temp == NULL) {
            return count;
        }
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    // Function to print the list
    void printList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Circular Linked List: ";
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    int choice, data, position;

    do {
        cout << "\n1. Insert at start\n2. Insert at end\n3. Insert at nth position\n4. Delete from start\n5. Delete from end\n6. Delete from nth position\n";
        cout << "7. Search for a key\n8. Update list\n9. Empty list\n10. Calculate size\n11. Print list\n12. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at start: ";
                cin >> data;
                list.insertAtStart(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtNth(data, position);
                break;
            case 4:
                list.deleteFromStart();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.deleteFromNth(position);
                break;
            case 7:
                cout << "Enter key to search for: ";
                cin >> data;
                if (list.search(data)) {
                    cout << "Key found in the list." << endl;
                } else {
                    cout << "Key not found in the list." << endl;
                }
                break;
            case 8:
                cout << "Enter data to update: ";
                cin >> data;
                cout << "Enter position to update at: ";
                cin >> position;
                list.update(data, position);
                break;
            case 9:
                if (list.isEmpty()) {
                    cout << "List is empty." << endl;
                } else {
                    cout << "List is not empty." << endl;
                }
                break;
            case 10:
                cout << "Size of the list: " << list.size() << endl;
                break;
            case 11:
                list.printList();
                break;
            case 12:
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 12);

    return 0;
}*/



