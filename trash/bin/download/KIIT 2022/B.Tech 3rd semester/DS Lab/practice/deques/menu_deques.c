// Write in c language a menu driven program to implement Deques (both Input-restricted and output-restricted) and performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int deque[MAX];
int front = -1;
int rear = -1;
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}
void insertRight(int x)
{
    if (isFull())
    {
        printf("Deque overflow\n");
        return;
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }

        else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
        deque[rear] = x;
    }
}
void insertLeft(int x)
{
    if (isFull())
    {
        printf("Deque overflow\n");
        return;
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = MAX - 1;
        else
            front--;
        deque[front] = x;
    }
}
int deleteLeft()
{
    if (isEmpty())
    {
        printf("Deque underflow\n");
        exit(1);
    }
    else
    {
        int x = deque[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
        return x;
    }
}
int deleteRight()
{
    if (isEmpty())
    {
        printf("Deque underflow\n");
        exit(1);
    }
    else
    {
        int x = deque[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
        return x;
    }
}
int peekLeft()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        exit(1);
    }
    else
    {
        return deque[front];
    }
}
int peekRight()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        exit(1);
    }
    else
    {
        return deque[rear];
    }
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    else
    {
        printf("The deque is: ");
        i = front;
        while (i != rear)
        {
            if (i == MAX - 1)
                i = 0;
            else
                i++;
        }
        printf("%d\n", deque[rear]);
    }
}
void inputRestricted()
{
    int choice;
    int x;
    while (1)
    {
        printf("Input restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            insertRight(x);
            break;
        case 2:
            x = deleteLeft();
            printf("%d deleted\n", x);
            break;
        case 3:
            x = deleteRight();
            printf("%d deleted\n", x);
            break;
        case 4:
            display();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}
void outputRestricted()
{
    int choice;
    int x;
    while (1)
    {
        printf("Output restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            insertRight(x);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            insertLeft(x);
            break;
        case 3:
            x = deleteLeft();
            printf("%d deleted\n", x);
            break;
        case 4:
            display();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}
int main()
{
    int type;
    printf("Enter the type of deque:\n");
    printf("1. Input restricted\n");
    printf("2. Output restricted\n");
    scanf("%d", &type);
    if (type == 1)
        inputRestricted();
    else if (type == 2)
        outputRestricted();
    else
        printf("Invalid type\n");

    return 0;
}