#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {6, 3, 5, 32, 2, 51, 69};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Pre. array: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Bubble Sort: ");
    printArray(arr, n);
    int Arr[] = {6, 3, 5, 32, 2, 51, 69};
    insertionSort(Arr, n);
    printf("Insertion Sort: ");
    printArray(Arr, n);
    return 0;
}