// Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array.

// Circular queue using array in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // maximum size of the queue

// Queue structure
struct queue
{
    int items[MAX]; // array to store the elements
    int front;      // index of the front element
    int rear;       // index of the rear element
    int size;       // current size of the queue
};

// Function to create a new queue
struct queue *createQueue(int capacity)
{
    struct queue *q = malloc(sizeof(struct queue)); // allocate memory for the queue
    q->front = -1;                                  // initialize front to -1
    q->rear = -1;                                   // initialize rear to -1
    q->size = 0;                                    // initialize size to 0
    return q;                                       // return the queue pointer
}

// Function to check if the queue is empty
int isEmpty(struct queue *q)
{
    if (q->size == 0) // if size is 0, queue is empty
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(struct queue *q)
{
    if (q->size == MAX) // if size is MAX, queue is full
        return 1;
    else
        return 0;
}

// Function to insert an element at the rear of the queue
void enqueue(struct queue *q, int value)
{
    if (isFull(q)) // if queue is full, print error message
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1) // if queue is empty, set front to 0
            q->front = 0;
        q->rear = (q->rear + 1) % MAX; // increment rear by 1 modulo MAX
        q->items[q->rear] = value;     // store the value at the rear index
        q->size++;                     // increment size by 1
    }
}

// Function to remove an element from the front of the queue
void dequeue(struct queue *q)
{
    int item;
    if (isEmpty(q)) // if queue is empty, print error message
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = q->items[q->front];             // get the front element
        q->front = (q->front + 1) % MAX;       // increment front by 1 modulo MAX
        q->size--;                             // decrement size by 1
        printf("Element deleted: %d\n", item); // print the deleted element
    }
}

// Function to display the elements of the queue
void traverse(struct queue *q)
{
    int i;
    if (isEmpty(q)) // if queue is empty, print error message
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        for (i = 0; i < q->size; i++) // loop from 0 to size-1
        {
            printf("%d  ", q->items[(q->front + i) % MAX]); // print each element using modulo arithmetic
        }
        printf("\n");
    }
}

// Function to display the main menu
void displayMenu()
{
    printf("Main Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
}

// Function to get the user's choice
int getOption()
{
    int option;
    printf("\nEnter option: ");
    scanf("%d", &option); // read the option from the user
    return option;        // return the option
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
    struct queue *q; 
    int capacity, option, value;

    printf("Enter Queue size: ");
    scanf("%d", &capacity); 
    if (capacity > MAX)    
    {
        printf("Size cannot exceed %d\n", MAX);
        exit(0);
    }

    q = createQueue(capacity); 

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
