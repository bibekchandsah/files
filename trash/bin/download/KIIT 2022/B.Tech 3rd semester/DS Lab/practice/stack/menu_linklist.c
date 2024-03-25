// Write a menu driven program to create a stack using linked list and perform the following operation using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}
int pop()
{
    if (top == NULL)
    {
        printf("Error: Stack underflow!\n");
        return -1;
    }
    int value = top->data;
    struct node *temp = top->next;
    free(top);
    top = temp;
    return value;
}
int isEmpty()
{
    return (top == NULL);
}
void traverse()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed into the stack: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("%d deleted from Stack\n", value);
            }
            break;
        case 3:
            if (isEmpty())
            {
                printf("Stack empty: True\n");
            }
            else
            {
                printf("Stack empty: False\n");
            }
            break;
        case 4:
            traverse();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option. Please enter a valid choice.\n");
            break;
        }
    }
}
