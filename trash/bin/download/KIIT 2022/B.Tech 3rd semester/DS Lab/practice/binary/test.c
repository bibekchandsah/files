#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Structure to represent a node in the adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent the graph
struct Graph
{
    int numVertices;
    struct Node *adjacencyList[MAX_VERTICES];
};

// Function to initialize a graph with a given number of vertices
void initializeGraph(struct Graph *graph, int vertices)
{
    graph->numVertices = vertices;

    // Initialize adjacency list for each vertex
    for (int i = 0; i < vertices; ++i)
    {
        graph->adjacencyList[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Create a new node for the destination vertex
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Function to perform Depth-First Search (DFS)
void DFS(struct Graph *graph, int start, int visited[])
{
    printf("%d ", start);
    visited[start] = 1;

    // Traverse all adjacent vertices
    struct Node *current = graph->adjacencyList[start];
    while (current != NULL)
    {
        if (!visited[current->data])
        {
            DFS(graph, current->data, visited);
        }
        current = current->next;
    }
}

// Function to perform Breadth-First Search (BFS)
void BFS(struct Graph *graph, int start, int visited[])
{
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Enqueue the starting vertex
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear)
    {
        // Dequeue a vertex and print it
        int current = queue[++front];
        printf("%d ", current);

        // Enqueue all adjacent vertices
        struct Node *temp = graph->adjacencyList[current];
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                queue[++rear] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

// Function to delete an edge from the graph
void deleteEdge(struct Graph *graph, int src, int dest)
{
    struct Node *current = graph->adjacencyList[src];
    struct Node *prev = NULL;

    // Find the edge in the adjacency list
    while (current != NULL && current->data != dest)
    {
        prev = current;
        current = current->next;
    }

    // If the edge is found, remove it
    if (current != NULL)
    {
        if (prev != NULL)
        {
            prev->next = current->next;
        }
        else
        {
            graph->adjacencyList[src] = current->next;
        }
        free(current);
        printf("Edge (%d, %d) deleted successfully.\n", src, dest);
    }
    else
    {
        printf("Edge (%d, %d) not found.\n", src, dest);
    }
}

// Function to search for an edge in the graph
void searchEdge(struct Graph *graph, int src, int dest)
{
    struct Node *current = graph->adjacencyList[src];

    // Search for the edge in the adjacency list
    while (current != NULL)
    {
        if (current->data == dest)
        {
            printf("Edge (%d, %d) found in the graph.\n", src, dest);
            return;
        }
        current = current->next;
    }

    printf("Edge (%d, %d) not found in the graph.\n", src, dest);
}

int main()
{
    struct Graph graph;
    int vertices, choice, src, dest;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    initializeGraph(&graph, vertices);

    while (1)
    {
        printf("\nGraph Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Depth-First Search (DFS)\n");
        printf("5. Breadth-First Search (BFS)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source and destination vertices (0 to %d): ", vertices - 1);
            scanf("%d %d", &src, &dest);
            addEdge(&graph, src, dest);
            break;
        case 2:
            printf("Enter source and destination vertices to delete edge: ");
            scanf("%d %d", &src, &dest);
            deleteEdge(&graph, src, dest);
            break;
        case 3:
            printf("Enter source and destination vertices to search edge: ");
            scanf("%d %d", &src, &dest);
            searchEdge(&graph, src, dest);
            break;
        case 4:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &src);
            printf("DFS Traversal: ");
            int visitedDFS[MAX_VERTICES] = {0};
            DFS(&graph, src, visitedDFS);
            break;
        case 5:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &src);
            printf("BFS Traversal: ");
            int visitedBFS[MAX_VERTICES] = {0};
            BFS(&graph, src, visitedBFS);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
