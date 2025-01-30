#include <stdio.h>
#include <math.h>
#include <string.h>

// Constants
#define MAX_LIST_SIZE 100    // Maximum size of the list
#define FALSE 0              // Define FALSE as 0
#define TRUE 1               // Define TRUE as 1

// Structure to represent an element in the list
typedef struct {
    int number;             // Integer number associated with the element
    char *string;           // Pointer to a string associated with the element
} ELEMENT_TYPE;

// Structure to represent the list
typedef struct {
    int last;               // Index of the last element in the list
    ELEMENT_TYPE a[MAX_LIST_SIZE]; // Array to store the elements
} LIST_TYPE;

// Window type (used to represent positions in the list)
typedef int WINDOW_TYPE;

// Function to return the position following the last element in the list
WINDOW_TYPE end(LIST_TYPE *list) {
    return (list->last + 1);  // Position after the last valid element
}

// Function to empty a list (set last to -1)
WINDOW_TYPE empty(LIST_TYPE *list) {
    list->last = -1;  // Mark the list as empty
    return end(list); // Return the position after the last element (which is empty now)
}

// Function to check if the list is empty
int is_empty(LIST_TYPE *list) {
    return (list->last == -1) ? TRUE : FALSE; // Return TRUE if list is empty
}

// Function to return the position of the first element in the list
WINDOW_TYPE first(LIST_TYPE *list) {
    if (is_empty(list) == FALSE) {
        return 0;  // Position of the first element if the list is not empty
    } else {
        return end(list); // If empty, return the position after the last element
    }
}

// Function to return the position of the last element in the list
WINDOW_TYPE last(LIST_TYPE *list) {
    return list->last; // Return the last element's index
}

// Function to get the position of the next element in the list
WINDOW_TYPE next(WINDOW_TYPE w, LIST_TYPE *list) {
    if (w == last(list)) {
        // Error handling if trying to move past the last element
        printf("Error: Can't find next after end of list.\n");
        return end(list); // Return the position after the last element
    } else if (w == end(list)) {
        // Error handling if trying to move past the end of the list
        printf("Error: Can't find next after end of list.\n");
        return end(list); // Return the position after the last element
    } else {
        return w + 1;  // Move to the next element
    }
}

// Function to get the position of the previous element in the list
WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list) {
    if (w != first(list)) {
        return w - 1;  // Move to the previous element if not already at the first element
    } else {
        // Error handling if trying to move before the first element
        printf("Error: Can't find previous before first element of list.\n");
        return w;  // Return the current position as is
    }
}

int main() {
    // Example usage
    LIST_TYPE list;
    empty(&list);  // Empty the list

    // Add some elements to the list
    ELEMENT_TYPE element1 = {1, "Element 1"};
    ELEMENT_TYPE element2 = {2, "Element 2"};
    list.a[0] = element1;  // Insert the first element
    list.a[1] = element2;  // Insert the second element
    list.last = 1;  // Set the last valid index (1 in this case)

    // Access elements using the window
    WINDOW_TYPE window = first(&list);  // Get the first element's position
    while (window != end(&list)) {  // Loop until we reach the end
        printf("Number: %d, String: %s\n", list.a[window].number, list.a[window].string);
        window = next(window, &list);  // Move to the next element
    }

    return 0;
}
