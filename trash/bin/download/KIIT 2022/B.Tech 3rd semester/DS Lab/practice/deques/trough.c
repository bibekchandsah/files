#include <stdio.h>
#include <stdlib.h>

// Define a node structure to represent each element of the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node with the given data
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    // If the tree is empty, return the new node as the root
    if (root == NULL)
    {
        return newNode(data);
    }
    // Else, recursively insert the node in the left or right subtree depending on the data
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        // Return the root of the modified tree
        return root;
    }
}

// Preorder traversal of the BST
void preorder(struct Node *root)
{
    // If the tree is not empty, print the root data, then traverse the left and right subtrees
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal of the BST
void postorder(struct Node *root)
{
    // If the tree is not empty, traverse the left and right subtrees, then print the root data
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Inorder traversal of the BST
void inorder(struct Node *root)
{
    // If the tree is not empty, traverse the left subtree, then print the root data, then traverse the right subtree
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search for an element in the BST
struct Node *search(struct Node *root, int data)
{
    // If the tree is empty or the root data matches the data, return the root
    if (root == NULL || root->data == data)
    {
        return root;
    }
    // Else, recursively search in the left or right subtree depending on the data
    else
    {
        if (data < root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }
}

// Define the main function
int main()
{
    // Declare a pointer to store the root of the BST
    struct Node *root = NULL;

    // Declare a variable to store the number of nodes
    int n;

    // Declare a variable to store the data of each node
    int data;

    // Declare a variable to store the choice of the user
    int choice;

    // Prompt and read the number of nodes from the user
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Prompt and read the elements of BST from the user
    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        // Call the function to insert the element into the BST
        root = insert(root, data);
    }

    // Print a message that the BST is created
    printf("BST Created: \n");

    // Call the function to display the BST
    display(root);

    // Use a loop to display a menu of options and perform the corresponding operations
    while (1)
    {
        // Print the menu
        printf("MAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter option: ");

        // Read the option from the user
        scanf("%d", &choice);

        // Perform the operation based on the option
        switch (choice)
        {
        case 1:
            // Call the function to perform the preorder traversal and print the result
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 2:
            // Call the function to perform the postorder traversal and print the result
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            // Call the function to perform the inorder traversal and print the result
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            // Prompt and read the element to be searched from the user
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            // Call the function to search for the element in the BST and store the result
            struct Node *result = search(root, data);
            // If the result is not NULL, print a message that the element is found
            if (result != NULL)
            {
                printf("%d is found\n", data);
            }
            // Else, print a message that the element is not found
            else
            {
                printf("%d is not found\n", data);
            }
            break;
        case 5:
            // Exit the loop
            printf("Thank you for using the program\n");
            exit(0);
        default:
            // Print an error message for invalid option
            printf("Invalid option\n");
        }
    }

    return 0;
}
