// write a c program to implement bubble short and insertion short
// sort algorithms.
#include<stdio.h>
void main()
{
    int i,j,n;
    printf("Enter the number of elements you want in array:");
    scanf("%d",&n);
    int arr[10];
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d = ",i+1);
        scanf("%d",&arr[i]);
        }
        printf("\nOriginal Array is:\n");
        for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
        printf("\nSorted Array using Bubble Sort Algorithm:\n");
        for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
        if (arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
            for(i=0;i<n;i++)
            printf("%d\t",arr[i]);
            printf("\nSorted Array using Insertion Sort Algorithm:\n");
            for(i=1;i<n;i++)
            {
                int key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                    }
                    arr[j + 1] = key;
                    }
                    for(i=0;i<n;i++)
                    printf("%d\t",arr[i]);
                    }
                    