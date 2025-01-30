#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1; // Return pivot index
}

// QuickSort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high); // Partition the array
        quicksort(arr, low, partitionIndex - 1); // Sort left half
        quicksort(arr, partitionIndex + 1, high); // Sort right half
    }
}

int main() {
    const int size = 4;
    int arr[size] = {5, 7, -1, 2};

    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, size - 1);

    cout << "Array after sorting:  ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
