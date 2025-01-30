#include <iostream>
using namespace std;

// Task 1: Selection Sort
/*
int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int* arr = new int[size]; // Using dynamic memory allocation

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Selection Sort Algorithm
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // Swap the smallest element found with the current position
    }

    cout << "\nSorted array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free allocated memory
    return 0;
}
*/

// Task 2: Bubble Sort
/*
int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int* arr = new int[size];

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Bubble Sort Algorithm
    for (int j = 0; j < size - 1; j++) {
        for (int k = 0; k < size - 1 - j; k++) { // Optimized to avoid redundant comparisons
            if (arr[k] > arr[k + 1]) {
                swap(arr[k], arr[k + 1]); // Swap elements if they are in the wrong order
            }
        }
    }

    cout << "\nSorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
*/

// Task 3: Insertion Sort
int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int* arr = new int[size];

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < size; i++) {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { // Shift elements to the right
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the element at the correct position
    }

    cout << "\nSorted array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}