#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
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
        return root;
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
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
int main()
{
    struct Node *root = NULL;
    int n;
    int data;
    int choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("BST Created: \n");
    display(root);
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

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            struct Node *result = search(root, data);
            if (result != NULL)
            {
                printf("%d is found\n", data);
            }
            else
            {
                printf("%d is not found\n", data);
            }
            break;
        case 5:
            printf("Thank you for using the program\n");
            exit(0);
        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}
