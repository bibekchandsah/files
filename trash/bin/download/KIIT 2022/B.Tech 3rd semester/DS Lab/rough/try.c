#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100], i, n, pos, ele, searrch_element, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("1. Insert an element\n2. Delete an element\n3.Searching an Element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the position where you want to insert the element: ");
        scanf("%d", &pos);

        printf("Enter the element to be inserted: ");
        scanf("%d", &ele);

        for (i = n - 1; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[pos] = ele;

        n++;

        printf("The new array is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        break;

    case 2:
        printf("Enter the position of the element to be deleted: ");
        scanf("%d", &pos);

        for (i = pos; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("The new array is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        break;

    case 3:

        printf("Enter the element you want to search: ");
        scanf("%d", &searrch_element);

        for (i = 0; i < n; i++)
        {
            if (arr[i] == searrch_element)
            {
                printf("Element found at position %d\n", i + 1);
                break;
            }
        }
        break;
    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}