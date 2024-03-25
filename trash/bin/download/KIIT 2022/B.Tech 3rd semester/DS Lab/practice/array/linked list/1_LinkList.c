#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createLinkList(int NumNode);
void printLinkList(struct node *head);
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
    printLinkList(head);
}
void printLinkList(struct node *head)
{
    struct node *current = head;
    printf("the data of link list is :- \n");
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
}