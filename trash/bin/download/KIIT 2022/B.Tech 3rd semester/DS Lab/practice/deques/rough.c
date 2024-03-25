#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the deque
#define MAX 10

// Declare a global array to store the deque
int deque[MAX];

// Declare global variables to store the front and rear indices of the deque
int front = -1;
int rear = -1;

// Define a function to check if the deque is empty
int isEmpty()
{
    // Return 1 if the front and rear indices are both -1, else return 0
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Define a function to check if the deque is full
int isFull()
{
    // Return 1 if the front and rear indices are adjacent or equal, else return 0
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

// Define a function to insert an element at the right end of the deque
void insertRight(int x)
{
    // Check if the deque is full, if yes, print an error message and exit the function
    if (isFull())
    {
        printf("Deque overflow\n");
        return;
    }
    else
    {
        // If the deque is empty, set both the front and rear indices to 0
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        // Else, if the rear index is at the last position, wrap it around to 0
        else if (rear == MAX - 1)
            rear = 0;
        // Else, increment the rear index by 1
        else
            rear++;

        // Store the element at the rear index of the array
        deque[rear] = x;
    }
}

// Define a function to insert an element at the left end of the deque
void insertLeft(int x)
{
    // Check if the deque is full, if yes, print an error message and exit the function
    if (isFull())
    {
        printf("Deque overflow\n");
        return;
    }
    else
    {
        // If the deque is empty, set both the front and rear indices to 0
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        // Else, if the front index is at the first position, wrap it around to the last position
        else if (front == 0)
            front = MAX - 1;
        // Else, decrement the front index by 1
        else
            front--;

        // Store the element at the front index of the array
        deque[front] = x;
    }
}

// Define a function to delete an element from the left end of the deque
int deleteLeft()
{
    // Check if the deque is empty, if yes, print an error message and exit the function
    if (isEmpty())
    {
        printf("Deque underflow\n");
        exit(1);
    }
    else
    {
        // Store the element at the front index of the array in a variable
        int x = deque[front];

        // If the deque has only one element, set both the front and rear indices to -1
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        // Else, if the front index is at the last position, wrap it around to 0
        else if (front == MAX - 1)
            front = 0;
        // Else, increment the front index by 1
        else
            front++;

        // Return the stored element
        return x;
    }
}

// Define a function to delete an element from the right end of the deque
int deleteRight()
{
    // Check if the deque is empty, if yes, print an error message and exit the function
    if (isEmpty())
    {
        printf("Deque underflow\n");
        exit(1);
    }
    else
    {
        // Store the element at the rear index of the array in a variable
        int x = deque[rear];

        // If the deque has only one element, set both the front and rear indices to -1
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        // Else, if the rear index is at the first position, wrap it around to the last position
        else if (rear == 0)
            rear = MAX - 1;
        // Else, decrement the rear index by 1
        else
            rear--;

        // Return the stored element
        return x;
    }
}

// Define a function to get the element at the left end of the deque
int peekLeft()
{
    // Check if the deque is empty, if yes, print an error message and exit the function
    if (isEmpty())
    {
        printf("Deque is empty\n");
        exit(1);
    }
    else
    {
        // Return the element at the front index of the array
        return deque[front];
    }
}

// Define a function to get the element at the right end of the deque
int peekRight()
{
    // Check if the deque is empty, if yes, print an error message and exit the function
    if (isEmpty())
    {
        printf("Deque is empty\n");
        exit(1);
    }
    else
    {
        // Return the element at the rear index of the array
        return deque[rear];
    }
}

// Define a function to display the deque
void display()
{
    // Declare a variable to store the index of the deque
    int i;

    // Check if the deque is empty, if yes, print a message and exit the function
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    else
    {
        // Print the elements of the deque from the front index to the rear index
        printf("The deque is: ");
        i = front;
        while (i != rear)
        {
            printf("%d ", deque[i]);
            // If the index is at the last position, wrap it around to 0
            if (i == MAX - 1)
                i = 0;
            // Else, increment the index by 1
            else
                i++;
        }
        // Print the element at the rear index
        printf("%d\n", deque[rear]);
    }
}

// Define a function to display the menu for input restricted deque
void inputRestricted()
{
    // Declare a variable to store the choice of the user
    int choice;

    // Declare a variable to store the element to be inserted or deleted
    int x;

    // Use a loop to display the menu and perform the corresponding operations
    while (1)
    {
        // Print the menu
        printf("Input restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");

        // Read the choice from the user
        scanf("%d", &choice);

        // Perform the operation based on the choice
        switch (choice)
        {
        case 1:
            // Prompt and read the element to be inserted from the user
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);

            // Call the function to insert the element at the right end
            insertRight(x);
            break;
        case 2:
            // Call the function to delete the element from the left end and print it
            x = deleteLeft();
            printf("%d deleted\n", x);
            break;
        case 3:
            // Call the function to delete the element from the right end and print it
            x = deleteRight();
            printf("%d deleted\n", x);
            break;
        case 4:
            // Call the function to display the deque
            display();
            break;
        case 5:
            // Exit the loop
            return;
        default:
            // Print an error message for invalid choice
            printf("Invalid choice\n");
        }
    }
}

// Define a function to display the menu for output restricted deque
void outputRestricted()
{
    // Declare a variable to store the choice of the user
    int choice;

    // Declare a variable to store the element to be inserted or deleted
    int x;

    // Use a loop to display the menu and perform the corresponding operations
    while (1)
    {
        // Print the menu
        printf("Output restricted Deque Menu\n");
        printf("1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete from left\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");

        // Read the choice from the user
        scanf("%d", &choice);

        // Perform the operation based on the choice
        switch (choice)
        {
        case 1:
            // Prompt and read the element to be inserted from the user
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);

            // Call the function to insert the element at the right end
            insertRight(x);
            break;
        case 2:
            // Prompt and read the element to be inserted from the user
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);

            // Call the function to insert the element at the left end
            insertLeft(x);
            break;
        case 3:
            // Call the function to delete the element from the left end and print it
            x = deleteLeft();
            printf("%d deleted\n", x);
            break;
        case 4:
            // Call the function to display the deque
            display();
            break;
        case 5:
            // Exit the loop
            return;
        default:
            // Print an error message for invalid choice
            printf("Invalid choice\n");
        }
    }
}

// Define the main function
int main()
{
    // Declare a variable to store the type of deque
    int type;

    // Prompt and read the type of deque from the user
    printf("Enter the type of deque:\n");
    printf("1. Input restricted\n");
    printf("2. Output restricted\n");
    scanf("%d", &type);

    // Call the corresponding function to display the menu for the chosen type of deque
    if (type == 1)
        inputRestricted();
    else if (type == 2)
        outputRestricted();
    else
        printf("Invalid type\n");

    return 0;
}
