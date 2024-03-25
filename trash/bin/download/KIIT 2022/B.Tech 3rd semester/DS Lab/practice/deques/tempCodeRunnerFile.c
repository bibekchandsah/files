#include <stdio.h>
#include <stdlib.h>

// Structure definition for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Structure definition for a stack
struct Stack {
    struct StackNode* top;
};

// Structure definition for a queue
struct Queue {
    struct Stack* stack1; // Main stack for enqueue operations
    struct Stack* stack2; // Temporary stack for dequeue operations
};

// Function prototypes
struct StackNode* createStackNode(int data);
struct Stack* createStack();
void push(struct Stack* stack, int data);
int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);
void enqueue(struct Queue* queue, int data);
int dequeue(struct Queue* queue);
void display(struct Queue* queue);

// Function to create a new stack node
struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct StackNode* temp = stack->top;
    int poppedItem = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedItem;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        exit(1);
    }

    if (isEmpty(queue->stack2)) {
        // Transfer elements from stack1 to stack2
        while (!isEmpty(queue->stack1)) {
            int item = pop(queue->stack1);
            push(queue->stack2, item);
        }
    }

    // Pop from stack2 (front of the queue)
    return pop(queue->stack2);
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    // Display elements in stack1 from the bottom to the top
    struct StackNode* current = queue->stack1->top;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Display elements in stack2 from the top to the bottom
    current = queue->stack2->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Create a queue using two stacks
    struct Queue queue;
    queue.stack1 = createStack();
    queue.stack2 = createStack();

    // Enqueue elements
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Display the initial queue
    display(&queue);

    // Dequeue an element
    int front = dequeue(&queue);
    printf("Dequeued element: %d\n", front);

    // Enqueue more elements
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    // Display the updated queue
    display(&queue);

    return 0;
}
