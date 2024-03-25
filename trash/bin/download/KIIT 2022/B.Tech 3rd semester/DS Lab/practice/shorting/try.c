#include <stdio.h>

// Function to perform recursive binary search
int binary_search(int arr[], int low, int high, int key)
{
    // Base case: if low is greater than high, the key is not found
    if (low > high)
    {
        return -1;
    }

    // Calculate the middle index
    int mid = (low + high) / 2;

    // Check if the key is found at the middle
    if (arr[mid] == key)
    {
        return mid; // Key found, return its index
    }
    else if (key < arr[mid])
    {
        // Key is smaller than the middle element, search the left half
        return binary_search(arr, low, mid - 1, key);
    }
    else
    {
        // Key is greater than the middle element, search the right half
        return binary_search(arr, mid + 1, high, key);
    }
}

// Function to print the array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // User input variables
    int n;
    int key;

    // Get input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Initialize the array
    int arr[n];

    // Get element values for the array
    for (int i = 0; i < n; ++i)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Print the array
    printf("Array: ");
    print_array(arr, n);
    // Get input for the key to search
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    // Print the array
    printf("Array: ");
    print_array(arr, n);

    // Perform the search and print the result
    int index = binary_search(arr, 0, n - 1, key);
    if (index != -1)
    {
        printf("Key %d found at index %d\n", key, index);
    }
    else
    {
        printf("Key %d not found\n", key);
    }

    return 0;
}
