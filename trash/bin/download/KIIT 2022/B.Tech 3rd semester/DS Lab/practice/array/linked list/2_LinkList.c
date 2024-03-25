#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void printList(struct Node *head) // It takes a pointer to the "head" of the linked list "(struct Node* head)" as its parameter. The function has a "void" return type, which means it doesn't return any value but is responsible for printing the elements of the linked list.
{
    struct Node *current = head; // a new pointer "current" is declared, and assign the value of "head". This variable will be used to traverse the linked list from the beginning to the end.

    while (current != NULL) // Start a "while" loop that iterates until current becomes "NULL", which means the end of the list is reached.
    {
        printf("%d -> ", current->data); // print the "data" of the "current" node
        current = current->next;         // Update "current" to point to the "next" node in the list
        //  After printing the data of the "current" node, the "current" pointer is updated to point to the next node in the list. This step is crucial to move through the list and print all the nodes.
    }
    printf("NULL\n"); // print “NULL” to indicate the end of the list.
}

int main()
{
    struct Node *head = NULL; // Initialize the head of the linked list as NULL. This line creates a pointer to the head of the linked list and sets it initially to NULL.
    int numNodes, data;       //  Declare two integer variables numNodes and data to store the number of nodes and the user-entered data for each node.

    // Ask the user for the number of nodes they want to create
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes); // Read the user's input for the number of nodes and store it in the numNodes variable.

    // Check if the entered "numNodes" is less than or equal to 0. If it is, display an error message, and exit the program with an error code (1) because a valid number of nodes must be greater than 0.
    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Exiting.\n");
        return 1; // Exit the program with an error code
    }

    // Loop to create and add nodes to the linked list
    for (int i = 0; i < numNodes; i++)
    // Start a loop that runs for "numNodes" iterations. In our example, it will run "number of" times to create "number of"  nodes.
    {
        // Create a new node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        // Inside the loop, dynamically allocate memory for a new node. This line creates a new node and assigns its address to the "newNode" pointer.

        // Check if the memory allocation for "newNode" failed (i.e., newNode is NULL). If allocation fails, display an error message and exit the program with an error code (1).
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1); // Exit the program in case of memory allocation failure
        }

        // Ask the user for data for the current node
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data); // Read the user's input for the data of the current node and store it in the "data" variable

        // Initialize the node with user-entered data
        newNode->data = data; // Set the "data" member of the "newNode" to the user-entered data.
        newNode->next = NULL; // Initialize the "next" pointer of the "newNode" to "NULL" since it's the last node in the beginning.

        // Add the new node to the linked list
        if (head == NULL) // Check if the "head" pointer is "NULL". If it is, it means this is the first node being added to the list, so set "head" to "newNode".
        {
            head = newNode; 
        }
        // adding a new node to the end of the linked list when the list is not empty (i.e., when "head" is not "NULL").
        else // If the list already has nodes, traverse the list using a "while" loop to find the last node (the one with a "NULL" "next" pointer) and add the "newNode" to the end of the list.

        {
            struct Node *current = head; // declares a pointer variable "curren"t of type "struct Node*" and assigns it the value of "head", which is a pointer to the first node of the linked list.
            // new pointer of type "struct Node*" named "current" is declared and initialized to point to the "head" of the linked list. This pointer will be used to traverse the linked list to find the last node.

            // traversing through all existing nodes and updating the "next" pointer of the last node to point to "newNode". The new node becomes the last node in the linked list.
            while (current->next != NULL) // continues as long as the "next" pointer of the "current" node is not "NULL"
            {
                current = current->next; // updates the value of "current" to point to the next node in the linked list.
                // updates the "current" pointer to point to the next node in the list "(current->next)". This step is essential to move through the list and check the next pointer of each node.
            }
            current->next = newNode; // assigns the address of "newNode" to the "next" pointer of the last node in the linked list, effectively adding "newNode" as a new node at the end of the list.
            //  the "current" pointer is pointing to the last node in the list. This line of code sets the next pointer of the last node to point to the "newNode", effectively adding the "newNode" as a new node at the end of the list.
        }
    }

    // Print the linked list
    printf("Linked List: "); // Display a message to indicate that the linked list is being printed.
    printList(head);         // Call the "printList" function to traverse and print the linked list starting from the "head" node.

    // Free dynamically allocated memory (not included in this basic example)

    return 0; // Exit the program with a success code (0).
}
