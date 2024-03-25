// WAP to create a singly linked list and perform the following operation i) shorting of linked list ii) searching from the  linked list iii) insert node at end
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverseLinkList(struct node *head);
void insertAtEnd(struct node *head);
int main()
{
    printf("enter the number of node you want to create :- ");
    int numNode;
    scanf("%d", &numNode);
    struct node *head = NULL;
    for (int i = 0; i < numNode; i++)
    {
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("memory allocation failed \n");
        }
        int data;
        printf("enter the data for %d node :- ", i + 1);
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
    insertAtEnd(head);
}
void traverseLinkList(struct node *head)
{
    struct node *current = head;
    printf("the data of linked list is :- ");
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
}
void insertAtEnd(struct node *head)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node)); // allocate dynamic memory for new node
    if (newNode == NULL)
    {
        printf("dynamic memory allocation failed \n");
    }
    int data;
    printf("\nenter the data for new node :- ");
    scanf("%d", &data);           // scan the data
    newNode->data = data;         // store the data
    newNode->next = NULL;         // make new node next NULL
    struct node *current = head;  // temp pointer for traversing list
    while (current->next != NULL) // traverse to the last node
    {
        current = current->next;
    }
    current->next = newNode; // link previous last node next to new node
    printf("data inserted successfully\n");
    traverseLinkList(head);
}
