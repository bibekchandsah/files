#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
struct node *createLinkList(int NumNode);
struct node *traverseLinkList(struct node *head);
struct node *insertAtSpecificPosition(struct node *head, int position);
int main()
{
    int numNode;
    printf("enter the number of node you want to create :- ");
    scanf("%d", &numNode);
    createLinkList(numNode);
    int Position;
    insertAtSpecificPosition(head, Position);
}
struct node *createLinkList(int NumNode)
{
    if (NumNode <= 0)
    {
        printf("invalid input\n");
    }
    struct node *head = NULL;
    for (int i = 0; i < NumNode; i++)
    {
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("memory allocation failed\n");
        }
        printf("enter the data for %d node :- ", i + 1);
        int data;
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    traverseLinkList(head);
}
struct node *traverseLinkList(struct node *head)
{
    struct node *current = head;
    printf("the data of link list is :- \n");
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
}

struct node *insertAtSpecificPosition(struct node *head, int position)
{
    printf("\nenter the postion of node you want to insert :- ");
    scanf("%d", &position);
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    int data;
    printf("enter the data for new node :- ");
    scanf("%d", &data);
    newNode->data = data;
    struct node *current = head;
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
        printf("Invalid positionn\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
    traverseLinkList(head);
}