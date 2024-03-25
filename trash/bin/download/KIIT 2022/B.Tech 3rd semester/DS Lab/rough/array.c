// WAP to create a 1-D array of n elements and perform the following menu based operations using function.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. traversal of the array
#include <stdio.h>

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, int position, int element)
{
    if (*size >= position)
    {
        for (int i = *size; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        (*size)++;
        printf("Element inserted successfully.\n");
    }
    else
    {
        printf("Invalid position for insertion.\n");
    }
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size, int position)
{
    if (position >= 1 && position <= *size)
    {
        for (int i = position - 1; i < *size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted successfully.\n");
    }
    else
    {
        printf("Invalid position for deletion.\n");
    }
}

// Function for linear search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to traverse and display the array
void traverseArray(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int size = 0;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Linear search\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (size < n)
            {
                int position, element;
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, position, element);
            }
            else
            {
                printf("Array is full.\n");
            }
            break;

        case 2:
            if (size > 0)
            {
                int position;
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
            }
            else
            {
                printf("Array is empty.\n");
            }
            break;

        case 3:
            if (size > 0)
            {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                int index = linearSearch(arr, size, element);
                if (index != -1)
                {
                    printf("Element found at position %d.\n", index + 1);
                }
                else
                {
                    printf("Element not found.\n");
                }
            }
            else
            {
                printf("Array is empty.\n");
            }
            break;

        case 4:
            if (size > 0)
            {
                traverseArray(arr, size);
            }
            else
            {
                printf("Array is empty.\n");
            }
            break;

        case 5:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
