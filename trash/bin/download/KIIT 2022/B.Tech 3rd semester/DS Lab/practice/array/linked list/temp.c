#include <stdio.h>
#include <stdlib.h>

// Define a struct for a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position in the linked list
struct Node *insertNode(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);

    if (position == 0)
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (current == NULL)
        {
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to traverse and print the linked list
void traverseLinkedList(struct Node *head)
{
    struct Node *current = head;
    printf("Linked List Data: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int numNodes;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertNode(head, data, i); // Insert each node at the end
    }

    // Traverse and print the linked list
    traverseLinkedList(head);

    int position, data;

    printf("Enter the position at which you want to insert a node: ");
    scanf("%d", &position);

    printf("Enter the data for the new node: ");
    scanf("%d", &data);

    // Insert a node at the specified position
    head = insertNode(head, data, position);

    // Traverse and print the updated linked list
    traverseLinkedList(head);

    // Free memory allocated for the linked list nodes
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
