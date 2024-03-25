#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createList(int n);
int search(int key);
void sort();
void insertNodeAtEnd(int data);
void displayList();

int main()
{
    int n, keyToSearch, choice, index, data;
    printf("Enter the number of nodes in list : ");
    scanf("%d", &n);

    createList(n);
    printf("\nTHE LIST IS :");
    displayList();

    printf("\nPress 1 for the searching of an element in the list : ");
    printf("\nPress 2 for the sorting in ascending order of list : ");
    printf("\nPress 3 for the insertion at end the linked list : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nEnter element to search: ");
        scanf("%d", &keyToSearch);

        index = search(keyToSearch);

        if (index >= 0)
        {
            printf("%d found in the list at position %d\n", keyToSearch, index + 1);
        }
        else
        {
            printf("%d not found in the list.\n", keyToSearch);
        }
    }
    else if (choice == 2)
    {
        sort();
        printf("\n AFTER SORTING THE LIST IS ");
        displayList();
    }
    else if (choice == 3)
    {

        printf("\nEnter data to insert at end of the list: ");
        scanf("%d", &data);
        insertNodeAtEnd(data);

        printf("\nData in the list \n");
        displayList();
    }
    else
    {
        printf("\n PLEASE ENTER ONLY 1/2/3 !!!");
    }
    return 0;
}

void createList(int num)
{
    int data;
    struct node *new_node, *temp;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nWE CANT ALLOCATE THE MEMORY !");
    }
    else
    {
        printf("\nENTER THE DATA OF 1ST NODE:");
        scanf("%d", &head->data);
        head->next = NULL;
        temp = head;
        printf("\n NOW CREATING THE REMANINNG %d NUMBERS OF NODES\n", num - 1);
        for (int i = 2; i <= num; i++)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            if (new_node == NULL)
            {
                printf("\n WE CANT ALLOCTE MEMORY ");
                break;
            }
            else
            {
                printf("\nENTER THE DATA OF %dTH NODE:", i);
                scanf("%d", &new_node->data);
                new_node->next = NULL;
                temp->next = new_node;
                temp = temp->next;
            }
        }
        printf("\n THE LIST IS CREATED  SUCCESFULLY ");
    }
}

int search(int key)
{
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }
    return (curNode != NULL) ? index : -1;
}

void sort()
{
    struct node *start, *run;
    int temp;
    for (start = head; start->next != NULL; start = start->next)
    {
        for (run = start->next; run != NULL; run = run->next)
        {
            if (start->data > run->data)
            {
                temp = start->data;
                start->data = run->data;
                run->data = temp;
            }
        }
    }
}

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void displayList()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d---->", temp->data);
            temp = temp->next;
        }
    }
    printf("NULL");
}