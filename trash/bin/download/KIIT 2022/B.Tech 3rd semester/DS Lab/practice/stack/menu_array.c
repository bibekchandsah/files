// Write a menu driven program to create a stack using array and perform the following operation using function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
int stack[MAX_SIZE];
int top = -1;
void push(int value);
int pop();
int empty();
int full();
void display();

int main()
{
    int digit, value;
    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check stack is empty or not\n");
        printf("4. Check stack is full or not\n");
        printf("5. Display stack elements\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &digit);

        switch (digit)
        {
        case 1:
            printf("enter the data to be push:- ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped element %d \n\n", value);
            }
            break;
        case 3:
            if (empty())
            {
                printf("Stack is Empty.\n\n");
            }
            else
            {
                printf("Stack is Not Empty.\n\n");
            }
            break;
        case 4:
            if (full())
            {
                printf("stack is full\n\n");
            }
            else
            {
                printf("stack is not full\n\n");
            }
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid input. Please enter a valid digit.\n");
        }
    }
}
void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("stack overflow\n\n");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow \n\n");
        return -1;
    }
    return stack[top--];
}

int empty()
{
    return (top == -1);
}

int full()
{
    return (top == MAX_SIZE - 1);
}

void display()
{
    int i;
    if (empty())
    {
        printf("stack is empty\n\n");
        return;
    }
    printf("stack data: ");
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n\n");
}