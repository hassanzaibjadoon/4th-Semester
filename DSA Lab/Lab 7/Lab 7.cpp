/*#include <iostream>
using namespace std;
//lab07 task01

// Function to find all peak elements in an array
void findPeakElements(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        // Check if arr[i] is a peak
        if ((i == 0 || arr[i] >= arr[i-1])&&(i == n - 1 || arr[i] >= arr[i + 1])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 4, 7, 6, 9, 8}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Peak elements in the array: ";
    findPeakElements(arr, n);
    return 0;
}
*/


/*#include <iostream>

using namespace std;
//task01 using binary search
// Function to find a peak element in an array
int findPeak(int arr[], int low, int high, int n) {
    // Find index of middle element
    int mid = low + (high - low) / 2;

    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
        (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
        return arr[mid]; // Found peak element
    }

    // If middle element is not peak and its left neighbor is greater
    // then left half must have a peak element
    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeak(arr, low, mid - 1, n); // Recur for left half
    }
    // If middle element is not peak and its right neighbor is greater
    // then right half must have a peak element
    else {
        return findPeak(arr, mid + 1, high, n); // Recur for right half
    }
}

// Driver code
int main() {
    int arr[] = {0, 10, 20, 5, 45, 50, 65, 90, 35, 25, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peak = findPeak(arr, 0, n - 1, n);
    cout << "Peak element is: " << peak << endl;

    return 0;
}
*/



#include <iostream>
using namespace std;
// Function to find a peak element in a 2D array
void findPeakElement(int matrix[][4], int rows, int cols, int& peakRow, int& peakCol) {
    int left = 0, right = cols - 1;
// Perform binary search on columns
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int maxRow = 0;
        // Find the row index with maximum value in the current column
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][mid] > matrix[maxRow][mid]) {
                maxRow = i;
            }}
        // Check if matrix[maxRow][mid] is a peak
        if ((mid == 0 || matrix[maxRow][mid] >= matrix[maxRow][mid - 1]) &&
            (mid == cols - 1 || matrix[maxRow][mid] >= matrix[maxRow][mid + 1])) {
            peakRow = maxRow; // Set peak row index
            peakCol = mid;     // Set peak column index
            return;
        } else if (mid > 0 && matrix[maxRow][mid - 1] > matrix[maxRow][mid]) {
            // Peak must be in the left half
            right = mid - 1;
        } else {
            // Peak must be in the right half
            left = mid + 1;
        }
    }
    // Peak not found
    peakRow = -1;
    peakCol = -1;
}
int main() {
    // Example 2D array
    int matrix[][4] = {{1, 3, 5, 9},
                       {2, 4, 8, 10},
                       {7, 6, 11, 12},
                       {13, 14, 15, 16}};
     // Dimensions of the array
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    // Variables to store peak indices
    int peakRow, peakCol;
    // Find peak element
    findPeakElement(matrix, rows, cols, peakRow, peakCol);
    // Output peak element
    if (peakRow != -1 && peakCol != -1)
        cout << "Peak element: " << matrix[peakRow][peakCol] << " at index (" << peakRow << ", " << peakCol << ")" << endl;
    else
        cout << "Peak element not found." << endl;
    return 0;
}
 
