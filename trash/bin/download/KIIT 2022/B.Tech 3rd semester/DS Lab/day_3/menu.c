// WAP to create a 1-D array of n elements and perform the following menu based operations using function.
// a. linear search to search an element
// b. traversal of the array

#include <stdio.h>
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
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
    int num;
    printf("Enter number of elements :- ");
    scanf("%d", &num);
    int array[num];
    printf("\nEnter %d integers :- ", num);
    for (int j = 0; j < num; ++j)
    {
        scanf("%d", &array[j]);
    }
    int size = num;
    while (1)
    {
        int choice;
        printf("\nMenu:\n");
        printf("1. Linear search\n");
        printf("2. Traverse the array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (size >= 0)
            {
                int element;
                printf("Enter the element to search :- ");
                scanf("%d", &element);
                int index = linearSearch(array, size, element);
                if (index != -1)
                {
                    printf("Element found at position %d.\n", index + 1);
                }
                else
                {
                    printf("Element is not present in this array.\n");
                }
            }
            else
            {
                printf("No data available.");
            }
            break;

        case 2:
            if (size > 0)
            {
                traverseArray(array, size);
            }
            else
            {
                printf("Array is empty.\n");
            }
            break;

        case 3:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    };
}
