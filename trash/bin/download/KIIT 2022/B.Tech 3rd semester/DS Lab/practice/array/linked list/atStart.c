#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createLinkList(int NumNode);
void traverseLinkList(struct node *head);
void insertAtBeginning(struct node *head);
int main()
{
    int numNode;
    printf("enter the number of node you want to create :- ");
    scanf("%d", &numNode);
    createLinkList(numNode);
    return 0;
}
void createLinkList(int NumNode)
{
    if (NumNode <= 0)
    {
        printf("invalid input i.e. it must be >= 1");
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
        scanf("%d", &newNode->data);
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
    insertAtBeginning(head);
}
void traverseLinkList(struct node *head)
{
    struct node *current = head;
    printf("the data of node is :- ");
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
}
void insertAtBeginning(struct node *head)
{
    struct node *newNode; // created a pointer named newNode of struct node type
    newNode = (struct node *)malloc(sizeof(struct node)); // allocated dynamic memory
    if (newNode == NULL) // checks whether the node is created or not
    {
        printf("memory allocation failed\n");
    }
    printf("\nenter the data for new inserting node :- "); // enter the data for newNode
    scanf("%d", &newNode->data); 
    newNode->next = head; // linking the head & newNode to previous first newNode i.e. now head & newNode both are pointing to previous first node 
    // where head is pointing at that place newNode->next is also pointing
    head = newNode; // linking i.e. pointing head to new newNode

    traverseLinkList(head);
}