// predefined node value 
#include <stdio.h>
#include <stdlib.h>
// declaration | representation of linked list
struct node
{
    int data;
    struct node *next;
};

// takes a pointer to the head of the linked list
void traverseLinkedList(struct node *pointer)
{
    // runs until pointer becomes NULL
    while (pointer != NULL)
    {
        printf("element :- %d \n", pointer->data);
        pointer = pointer->next;
    }
}
int main()
{
    // creating pointer i.e. like "int *pointer"
    struct node *head;
    struct node *second;
    struct node *third;

    // creating dynamic memory
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // linking of first & second node
    head->data = 2;
    head->next = second;

    // linking of second & third node
    second->data = 3;
    second->next = third;

    // terminate the list at third node
    third->data = 4;
    third->next = NULL;

    // function is called with the head pointer
    traverseLinkedList(head);
}