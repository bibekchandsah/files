// Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,  IsEmpty, Traverse using single linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          
    struct node *next; 
};

struct queue
{
    struct node *front; 
    struct node *rear;  
};

struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue)); 
    q->front = NULL;                               
    q->rear = NULL;                                
    return q;                                      
}

struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node)); 
    newNode->data = value;                              
    newNode->next = NULL;                               
    return newNode;                                     
}

int isEmpty(struct queue *q)
{
    if (q->front == NULL) 
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int value)
{
    struct node *newNode = createNode(value); 
    if (isEmpty(q))                           
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode; 
        q->rear = newNode;       
    }
}

void dequeue(struct queue *q)
{
    struct node *temp;
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = q->front;           
        q->front = q->front->next; 
        if (q->front == NULL)      
            q->rear = NULL;
        printf("Element deleted: %d\n", temp->data); 
        free(temp);                                 
    }
}

void traverse(struct queue *q)
{
    struct node *temp;
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        temp = q->front;    
        while (temp != NULL) 
        {
            printf("%d  ", temp->data); 
            temp = temp->next;          
        }
        printf("\n");
    }
}

void displayMenu()
{
    printf("\n***************\n");
    printf("Main Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
}

int getOption()
{
    int option;
    printf("\nEnter option: ");
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
    int option, value;

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
            traverse(q); 
            break;
        case 5: 
            printf("Exiting the program\n");
            break;
        default: 
            printf("Invalid option\n");
            break;
        }
    } while (option != 5); 

    return 0;
}
