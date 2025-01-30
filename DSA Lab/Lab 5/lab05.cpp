#include <iostream>
using namespace std;

// Task 01: Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i; // Return the index where key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Task 02: Binary Search (Only works on sorted arrays)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid; // Key found
        } else if (arr[mid] < key) {
            left = mid + 1; // Ignore left half
        } else {
            right = mid - 1; // Ignore right half
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60}; // Sorted array for Binary Search
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, choice;

    cout << "Enter the element to search: ";
    cin >> key;

    cout << "Choose Search Method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (Requires Sorted Array)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    int index = -1;
    if (choice == 1) {
        index = linearSearch(arr, n, key);
    } else if (choice == 2) {
        index = binarySearch(arr, 0, n - 1, key);
    } else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
        return 1;
    }

    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
