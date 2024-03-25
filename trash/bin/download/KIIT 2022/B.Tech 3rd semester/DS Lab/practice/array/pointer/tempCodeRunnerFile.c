#include <stdio.h>
int main()
{
   int array[3][3];
   int *pointer;
   pointer = &array[0][0];
   int size = sizeof(array) / sizeof(array[0][0]);
   printf("enter %d element :- ", size);
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         scanf("%d", &array[i][j]);
      }
   }
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         printf("%d\t", *(array + i) + j); // address
         // printf("%d\t", *(*(array + i) + j)); // value
         // printf("%d\t", array[i] + j); // address
         // printf("%d\t", *(array[i] + j)); // value
      }
      printf("\n");
   }
   printf("%d\n", &array[1] + 1); // address of 2nd row 2nd column i.e. [2][0] ==> base address of array[1] + size of array i.e. (3 column * 4 byte)

   printf("%d\n", **array);       // value of 1st row 1st column i.e. [0][0]
   printf("%d\n", *(*array + 0)); // value of 1st row 2nd column i.e. [0][0]
   printf("%d\n", *(*array + 1)); // value of 1st row 2nd column i.e. [0][1]
   printf("%d\n", *(*array + 2)); // value of 1st row 2nd column i.e. [0][1]
}