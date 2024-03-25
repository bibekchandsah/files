// Write a program in c language to create a binary search tree of n data elements using linked list and perform the following menu driven operations:
//  insert an element to the BST
//  delete an element to the BST
//  search an element to the BST
//  display the largest element
//  display the smallest element
//  display the level
//  height of a node
//  count number of leaf nodes

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int data)
{

    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct node *search(struct node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

struct node *minValueNode(struct node *root)
{
    struct node *current = root;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *delete(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

void displayLargest(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    struct node *current = root;
    while (current && current->right != NULL)
        current = current->right;
    printf("The largest element is %d.\n", current->data);
}

void displaySmallest(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    struct node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    printf("The smallest element is %d.\n", current->data);
}

void displayLevel(struct node *root, int data, int level)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    if (root->data == data)
    {
        printf("The level of %d is %d.\n", data, level);
        return;
    }
    if (data < root->data)
        displayLevel(root->left, data, level + 1);
    else
        displayLevel(root->right, data, level + 1);
}

int height(struct node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void displayHeight(struct node *root, int data)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    if (root->data == data)
    {
        printf("The height of %d is %d.\n", data, height(root));
        return;
    }
    if (data < root->data)
        displayHeight(root->left, data);
    else
        displayHeight(root->right, data);
}

int countLeaves(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void displayLeaves(struct node *root)
{
    if (root == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    printf("The number of leaf nodes is %d.\n", countLeaves(root));
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {

        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int n, data, choice;
    printf("Enter the number of elements to be inserted in the tree: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data value: ");
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("The tree in inorder traversal is: ");
    inorder(root);
    printf("\n");
    printf("The tree in preorder traversal is: ");
    preorder(root);
    printf("\n");
    printf("The tree in postorder traversal is: ");
    postorder(root);
    printf("\n");
    while (1)
    {
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
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data value: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("The updated tree in inorder traversal is: ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Enter the data value: ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("The updated tree in inorder traversal is: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter the data value: ");
            scanf("%d", &data);
            struct node *result = search(root, data);
            if (result != NULL)
                printf("%d is found in the tree.\n", data);
            else
                printf("%d is not found in the tree.\n", data);
            break;
        case 4:
            displayLargest(root);
            break;
        case 5:
            displaySmallest(root);
            break;
        case 6:
            printf("Enter the data value: ");
            scanf("%d", &data);
            displayLevel(root, data, 1);
            break;
        case 7:
            printf("Enter the data value: ");
            scanf("%d", &data);
            displayHeight(root, data);
            break;
        case 8:
            displayLeaves(root);
            break;
        case 9:
            printf("Thank you for using the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}
