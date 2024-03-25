// user enter the no. of node & data of node 
#include <stdio.h>
#include <stdlib.h>

// Declaration and representation of a linked list node
struct node
{
    int data;
    struct node *next;
};

// Function to traverse and print the linked list
void traverseLinkedList(struct node *pointer)
{
    while (pointer != NULL)
    {
        printf("Element: %d\n", pointer->data);
        pointer = pointer->next;
    }
}

int main()
{
    struct node *head = NULL; // Initialize the head of the linked list as NULL
    int numElements;

    printf("Enter the number of elements you want to add to the linked list: ");
    scanf("%d", &numElements);

    if (numElements <= 0)
    {
        printf("Invalid number of elements. Exiting.\n");
        return 1; // Exit the program with an error code
    }

    // Temporary pointer to keep track of the last node
    struct node *temp = NULL;

    for (int i = 0; i < numElements; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1); // Exit the program in case of memory allocation failure
        }

        printf("Enter element %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Call the function to traverse and print the linked list
    printf("Linked List:\n");
    traverseLinkedList(head);

    // Free dynamically allocated memory (not included in this basic example)

    return 0;
}