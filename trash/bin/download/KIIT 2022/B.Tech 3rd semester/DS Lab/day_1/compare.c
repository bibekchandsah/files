// Write a program to read two numbers and compare the numbers using function call by address.
#include <stdio.h>

void compareNumbers(int *num1, int *num2, char *result)
{
    if (*num1 == *num2)
    {
        *result = '=';
    }
    else if (*num1 < *num2)
    {
        *result = '<';
    }
    else
    {
        *result = '>';
    }
}

int main()
{
    int number1, number2;
    char result;

    printf("Enter the first number: ");
    scanf("%d", &number1);

    printf("Enter the second number: ");
    scanf("%d", &number2);

    compareNumbers(&number1, &number2, &result);

    printf("%d %c %d\n", number1, result, number2);

    return 0;
}
