#include <stdio.h>
#include <stdlib.h>

// Define a node structure to represent each element of the queue
struct Node
{
	int data;
	struct Node *next;
};

// Define a queue structure to represent the queue
struct Queue
{
	struct Node *front;
	struct Node *rear;
};

// Initialize the queue
void initQueue(struct Queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
	return q->front == NULL;
}

// Enqueue an element into the queue
void enqueue(struct Queue *q, int data)
{
	// Create a new node with the given data
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	// If the queue is empty, set both the front and rear pointers to the new node
	if (isEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		// Otherwise, set the next pointer of the current rear node to the new node and update the rear pointer to the new node
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

// Dequeue an element from the queue
int dequeue(struct Queue *q)
{
	// Check if the queue is empty
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}

	// Store the data of the front node in a variable
	struct Node *temp = q->front;
	int data = temp->data;

	// Update the front pointer to the next node
	q->front = q->front->next;

	// If the front pointer is NULL, set the rear pointer to NULL as well
	if (q->front == NULL)
	{
		q->rear = NULL;
	}

	// Free the memory allocated for the dequeued node
	free(temp);

	// Return the stored data
	return data;
}

// Get the rear element of the queue
int getRear(struct Queue *q)
{
	// Check if the queue is empty
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}

	// Return the data of the rear node
	return q->rear->data;
}

// Get the front element of the queue
int getFront(struct Queue *q)
{
	// Check if the queue is empty
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return -1;
	}

	// Return the data of the front node
	return q->front->data;
}

// Display the queue
void display(struct Queue *q)
{
	// Check if the queue is empty
	if (isEmpty(q))
	{
		printf("Queue is empty.\n");
		return;
	}

	// Loop from the front node to the rear node of the queue and print each element
	struct Node *temp = q->front;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Define the main function
int main()
{
	// Declare a variable to store the choice of the user
	int choice;

	// Declare a variable to store the element to be enqueued or dequeued
	int element;

	// Initialize the queue
	struct Queue q;
	initQueue(&q);

	// Use a loop to display the menu and get the user's choice
	while (1)
	{
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Get Rear\n");
		printf("4. Get Front\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element to be enqueued: ");
			scanf("%d", &element);
			enqueue(&q, element);
			break;
		case 2:
			element = dequeue(&q);
			if (element != -1)
			{
				printf("The dequeued element is %d.\n", element);
			}
			break;
		case 3:
			element = getRear(&q);
			if (element != -1)
			{
				printf("The rear element is %d.\n", element);
			}
			break;
		case 4:
			element = getFront(&q);
			if (element != -1)
			{
				printf("The front element is %d.\n", element);
			}
			break;
		case 5:
			// Call the function to display the queue
			display(&q);
			break;
		case 6:
			// Exit the loop
			printf("Thank you for using the program\n");
			exit(0);
		default:
			// Print an error message for invalid choice
			printf("Invalid choice\n");
		}
	}

	return 0;
}
