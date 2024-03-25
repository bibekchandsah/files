// searching, height, smallest,display level, deleting
#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
struct node
{
    int data;           // Data value
    struct node *left;  // Pointer to left child
    struct node *right; // Pointer to right child
};

// Create a new node with a given data value
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // Allocate memory
    temp->data = data;                                              // Assign data value
    temp->left = NULL;                                              // Initialize left child as NULL
    temp->right = NULL;                                             // Initialize right child as NULL
    return temp;                                                    // Return the new node
}

// Insert a new node in the binary search tree
struct node *insert(struct node *root, int data)
{
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(data);

    // Otherwise, recur down the tree
    if (data < root->data) // If data is less than root's data, insert in the left subtree
        root->left = insert(root->left, data);
    else if (data > root->data) // If data is more than root's data, insert in the right subtree
        root->right = insert(root->right, data);

    // Return the unchanged root pointer
    return root;
}

// Search for a given data value in the binary search tree
struct node *search(struct node *root, int data)
{
    // If the tree is empty or the data is found, return the root
    if (root == NULL || root->data == data)
        return root;

    // Otherwise, recur down the tree
    if (data < root->data) // If data is less than root's data, search in the left subtree
        return search(root->left, data);
    else // If data is more than root's data, search in the right subtree
        return search(root->right, data);
}

// Find the minimum value node in the binary search tree
struct node *minValueNode(struct node *root)
{
    struct node *current = root; // Start from the root node

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    // Return the node with the minimum value
    return current;
}

// Delete a node from the binary search tree
struct node *delete(struct node *root, int data)
{
    // If the tree is empty, return NULL
    if (root == NULL)
        return root;

    // Otherwise, recur down the tree
    if (data < root->data) // If data is less than root's data, delete from the left subtree
        root->left = delete (root->left, data);
    else if (data > root->data) // If data is more than root's data, delete from the right subtree
        root->right = delete (root->right, data);
    else
    { // If data is equal to root's data, this is the node to be deleted
        // Case 1: Node has no child or one child
        if (root->left == NULL)
        {
            struct node *temp = root->right; // Store the right child
            free(root);                      // Free the current node
            return temp;                     // Return the right child
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left; // Store the left child
            free(root);                     // Free the current node
            return temp;                    // Return the left child
        }

        // Case 2: Node has two children
        // Find the inorder successor (smallest node in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder successor's data to the current node
        root->data = temp->data;

        // Delete the inorder successor from the right subtree
        root->right = delete (root->right, temp->data);
    }

    // Return the updated root pointer
    return root;
}

// Display the largest element in the binary search tree
void displayLargest(struct node *root)
{
    // If the tree is empty, print a message
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }

    // Otherwise, find the rightmost node
    struct node *current = root; // Start from the root node

    // Loop down to find the rightmost leaf
    while (current && current->right != NULL)
        current = current->right;

    // Print the data of the rightmost node
    printf("The largest element is %d.\n", current->data);
}

// Display the smallest element in the binary search tree
void displaySmallest(struct node *root)
{
    // If the tree is empty, print a message
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }

    // Otherwise, find the leftmost node
    struct node *current = root; // Start from the root node

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    // Print the data of the leftmost node
    printf("The smallest element is %d.\n", current->data);
}

// Display the level of a given node in the binary search tree
void displayLevel(struct node *root, int data, int level)
{
    // If the tree is empty, print a message
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }

    // If the data is found, print the level
    if (root->data == data)
    {
        printf("The level of %d is %d.\n", data, level);
        return;
    }

    // Otherwise, recur down the tree
    if (data < root->data) // If data is less than root's data, go to the left subtree
        displayLevel(root->left, data, level + 1);
    else // If data is more than root's data, go to the right subtree
        displayLevel(root->right, data, level + 1);
}

// Find the height of a given node in the binary search tree
int height(struct node *root)
{
    // If the tree is empty or a leaf node, return 0
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    // Otherwise, find the maximum of the heights of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return the maximum height plus one
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Display the height of a given node in the binary search tree
void displayHeight(struct node *root, int data)
{
    // If the tree is empty, print a message
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }

    // If the data is found, print the height
    if (root->data == data)
    {
        printf("The height of %d is %d.\n", data, height(root));
        return;
    }

    // Otherwise, recur down the tree
    if (data < root->data) // If data is less than root's data, go to the left subtree
        displayHeight(root->left, data);
    else // If data is more than root's data, go to the right subtree
        displayHeight(root->right, data);
}

// Count the number of leaf nodes in the binary search tree
int countLeaves(struct node *root)
{
    // If the tree is empty, return 0
    if (root == NULL)
        return 0;

    // If the node is a leaf, return 1
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Otherwise, return the sum of the number of leaves in the left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// Display the number of leaf nodes in the binary search tree
void displayLeaves(struct node *root)
{
    // If the tree is empty, print a message
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }

    // Otherwise, print the number of leaf nodes
    printf("The number of leaf nodes is %d.\n", countLeaves(root));
}

// Display the binary search tree in inorder traversal
void inorder(struct node *root)
{
    // If the tree is not empty
    if (root != NULL)
    {
        // Recur on the left subtree
        inorder(root->left);

        // Print the root's data
        printf("%d ", root->data);

        // Recur on the right subtree
        inorder(root->right);
    }
}

// Display the binary search tree in preorder traversal
void preorder(struct node *root)
{
    // If the tree is not empty
    if (root != NULL)
    {
        // Print the root's data
        printf("%d ", root->data);

        // Recur on the left subtree
        preorder(root->left);

        // Recur on the right subtree
        preorder(root->right);
    }
}

// Display the binary search tree in postorder traversal
void postorder(struct node *root)
{
    // If the tree is not empty
    if (root != NULL)
    {
        // Recur on the left subtree
        postorder(root->left);

        // Recur on the right subtree
        postorder(root->right);

        // Print the root's data
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    struct node *root = NULL; // Initialize the root of the tree as NULL
    int n, data, choice;      // Declare variables for number of elements, data value, and menu choice

    // Ask the user to enter the number of elements to be inserted in the tree
    printf("Enter the number of elements to be inserted in the tree: ");
    scanf("%d", &n);

    // Loop to insert n elements in the tree
    for (int i = 0; i < n; i++)
    {
        // Ask the user to enter the data value
        printf("Enter the data value: ");
        scanf("%d", &data);

        // Insert the data value in the tree
        root = insert(root, data);
    }

    // Display the tree in inorder, preorder, and postorder traversals
    printf("The tree in inorder traversal is: ");
    inorder(root);
    printf("\n");

    printf("The tree in preorder traversal is: ");
    preorder(root);
    printf("\n");

    printf("The tree in postorder traversal is: ");
    postorder(root);
    printf("\n");

    // Loop to perform menu driven operations
    while (1)
    {
        // Display the menu options
        printf("Choose one of the following operations:\n");
        printf("1. Insert an element to the BST\n");
        printf("2. Delete an element from the BST\n");
        printf("3. Search an element in the BST\n");
        printf("4. Display the largest element\n");
        printf("5. Display the smallest element\n");
        printf("6. Display the level of an element\n");
        printf("7. Display the height of an element\n");
        printf("8. Display the number of leaf nodes\n");
        printf("9. Exit\n");

        // Ask the user to enter their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the operation based on the choice
        switch (choice)
        {
        case 1: // Insert an element to the BST
            // Ask the user to enter the data value
            printf("Enter the data value: ");
            scanf("%d", &data);

            // Insert the data value in the tree
            root = insert(root, data);

            // Display the updated tree in inorder traversal
            printf("The updated tree in inorder traversal is: ");
            inorder(root);
            printf("\n");
            break;

        case 2: // Delete an element from the BST
            // Ask the user to enter the data value
            printf("Enter the data value: ");
            scanf("%d", &data);

            // Delete the data value from the tree
            root = delete (root, data);

            // Display the updated tree in inorder traversal
            printf("The updated tree in inorder traversal is: ");
            inorder(root);
            printf("\n");
            break;

        case 3: // Search an element in the BST
            // Ask the user to enter the data value
            printf("Enter the data value: ");
            scanf("%d", &data);

            // Search for the data value in the tree
            struct node *result = search(root, data);

            // If the data value is found, print a message
            if (result != NULL)
                printf("%d is found in the tree.\n", data);
            // Otherwise, print a message
            else
                printf("%d is not found in the tree.\n", data);
            break;

        case 4: // Display the largest element
            // Call the function to display the largest element
            displayLargest(root);
            break;

        case 5: // Display the smallest element
            // Call the function to display the smallest element
            displaySmallest(root);
            break;

        case 6: // Display the level of an element
            // Ask the user to enter the data value
            printf("Enter the data value: ");
            scanf("%d", &data);

            // Call the function to display the level of the element
            displayLevel(root, data, 1);
            break;

        case 7: // Display the height of an element
            // Ask the user to enter the data value
            printf("Enter the data value: ");
            scanf("%d", &data);

            // Call the function to display the height of the element
            displayHeight(root, data);
            break;

        case 8: // Display the number of leaf nodes
            // Call the function to display the number of leaf nodes
            displayLeaves(root);
            break;

        case 9: // Exit
            // Print a message and exit the loop
            printf("Thank you for using the program.\n");
            exit(0);

        default: // Invalid choice
            // Print a message and ask the user to enter a valid choice
            printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0; // Return 0 to indicate normal termination
}
