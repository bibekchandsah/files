// Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
struct queue
{
    int items[MAX];
    int front;
    int rear;
};

struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == MAX - 1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

void dequeue(struct queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Queue is reset\n");
            q->front = q->rear = -1;
        }
        printf("Element deleted: %d\n", item);
    }
}

void traverse(struct queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d  ", q->items[i]);
        }
        printf("\n");
    }
}

void displayMenu()
{
    printf("\n****************\n");
    printf("Main Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
}

int getOption()
{
    int option;
    printf("Enter option: ");
    scanf("%d", &option);
    return option;
}

int getInput()
{
    int value;
    printf("Enter element: ");
    scanf("%d", &value);
    return value;
}

int main()
{
    struct queue *q = createQueue();
    int size, option, value;

    printf("\n...........................\n");
    printf("Enter the size of Queue: ");
    scanf("%d", &size);
    if (size > MAX)
    {
        printf("Size cannot exceed %d\n", MAX);
        exit(0);
    }

    do
    {
        displayMenu();
        option = getOption();
        switch (option)
        {
        case 1:
            value = getInput();
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            if (isEmpty(q))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 4:
            if (isFull(q))
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;
        case 5:
            traverse(q);
            break;
        case 6:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (option != 6);

    return 0;
}
