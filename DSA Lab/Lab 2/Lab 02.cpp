#include<iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If element is smaller than pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QuickSort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Function to merge two arrays
void mergeArray(int arrA[], int sizeA, int arrB[], int sizeB) {
    int newSize = sizeA + sizeB;
    int mergedArray[newSize];

    for(int i = 0; i < sizeA; i++) {
        mergedArray[i] = arrA[i];
    }
    for(int i = 0; i < sizeB; i++) {
        mergedArray[sizeA + i] = arrB[i];
    }

    cout << "Merged Array: ";
    for(int i = 0; i < newSize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {5, 7, -1, 2};
    int size = 4;

    cout << "Array before sorting:" << endl;    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, size - 1);
    
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Merging two arrays
    int size1, size2;
    cout << "Enter size of the first array: ";
    cin >> size1;
    cout << "Enter size of the second array: ";
    cin >> size2;

    int arr1[size1], arr2[size2];

    cout << "Enter the elements of the first array" << endl;
    for(int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the elements of the second array" << endl;
    for(int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }
    
    mergeArray(arr1, size1, arr2, size2);

    return 0;
}
