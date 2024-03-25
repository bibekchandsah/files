// loop runs continuously after each node
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the singly linked list
struct node
{
    int data;          // Data stored in the node
    struct node *next; // Pointer to the next node
};

int main()
{
    //  "head" for the head of the linked list, "newnode" for creating new nodes, and "temp" for traversing the linked list
    struct node *head, *newnode, *temp;
    head = NULL; // Initialize the head of the linked list as NULL

    int choice; // Variable to store user's choice (0 or 1)
    do
    {
        // Allocate memory for a new node
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1); // Exit the program in case of memory allocation failure
        }

        // Input data for the new node
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL; // Initialize the next pointer of the new node

        if (head == NULL)
        {
            // If the list is empty, set the new node as the head
            head = temp = newnode;
        }
        else
        {
            // Otherwise, add the new node to the end of the list
            temp->next = newnode;
            temp = newnode;
        }

        // Ask the user if they want to continue
        printf("Do you want to continue (0 to exit, 1 to continue): ");
        scanf("%d", &choice);
    } while (choice == 1); // Continue adding nodes if the user enters 1

    // Traverse and print the linked list
    temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n"); // Print a new line at the end for readability

    // Free dynamically allocated memory (not included in this basic example)

    return 0;
}
