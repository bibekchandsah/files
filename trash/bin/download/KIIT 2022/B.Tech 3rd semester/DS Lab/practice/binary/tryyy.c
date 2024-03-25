#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function prototypes
struct Node* createNode(int data);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void deleteEdge(struct Graph* graph, int src, int dest);
void displayGraph(struct Graph* graph);
int searchNode(struct Graph* graph, int key);
void traverseGraph(struct Graph* graph);
void printMenu();

int main() {
    int choice, src, dest, key;
    
    // Initialize the graph
    struct Graph* graph = NULL;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create graph
                printf("Enter the number of vertices: ");
                scanf("%d", &key);
                graph = createGraph(key);
                break;
            case 2:
                // Add edge
                printf("Enter source and destination vertices for the edge: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 3:
                // Delete edge
                printf("Enter source and destination vertices for the edge to delete: ");
                scanf("%d %d", &src, &dest);
                deleteEdge(graph, src, dest);
                break;
            case 4:
                // Display graph
                displayGraph(graph);
                break;
            case 5:
                // Search node
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (searchNode(graph, key))
                    printf("Node %d found in the graph.\n", key);
                else
                    printf("Node %d not found in the graph.\n", key);
                break;
            case 6:
                // Traverse graph
                printf("Traversal of the graph: ");
                traverseGraph(graph);
                printf("\n");
                break;
            case 7:
                // Exit
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 7);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;

    printf("Graph with %d vertices created.\n", numVertices);
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex and add it to the adjacency list of the source vertex
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;

    printf("Edge (%d, %d) added to the graph.\n", src, dest);
}

// Function to delete an edge from the graph
void deleteEdge(struct Graph* graph, int src, int dest) {
    // Search for the destination vertex in the adjacency list of the source vertex
    struct Node* current = graph->adjList[src];
    struct Node* prev = NULL;

    // Traverse the adjacency list to find the edge to be deleted
    while (current != NULL && current->data != dest) {
        prev = current;
        current = current->next;
    }

    // If the edge is found, remove it
    if (current != NULL) {
        if (prev == NULL)
            graph->adjList[src] = current->next;
        else
            prev->next = current->next;

        free(current);

        printf("Edge (%d, %d) deleted from the graph.\n", src, dest);
    } else {
        printf("Edge (%d, %d) not found in the graph.\n", src, dest);
    }
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    printf("Graph:\n");

    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* current = graph->adjList[i];
        printf("Vertex %d: ", i);

        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    }
}

// Function to search for a node in the graph
int searchNode(struct Graph* graph, int key) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* current = graph->adjList[i];

        while (current != NULL) {
            if (current->data == key)
                return 1; // Node found
            current = current->next;
        }
    }

    return 0; // Node not found
}

// Function to traverse the graph using Depth-First Search (DFS)
void traverseGraphDFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("%d ", vertex);

    // Traverse all adjacent vertices
    struct Node* current = graph->adjList[vertex];
    while (current != NULL) {
        if (!visited[current->data])
            traverseGraphDFS(graph, current->data, visited);
        current = current->next;
    }
}

// Function to traverse the graph using Breadth-First Search (BFS)
void traverseGraphBFS(struct Graph* graph) {
  // Create a queue to store the vertices to be visited
  struct Node* queue[graph->numVertices];
  int front = 0, rear = 0;

  // Mark all vertices as not visited
  int* visited = (int*)malloc(graph->numVertices * sizeof(int));
  for (int i = 0; i < graph->numVertices; ++i) {
    visited[i] = 0;
  }

  // Enqueue the starting vertex
  visited[0] = 1;
  queue[rear++] = graph->adjList[0];

  // Traverse the graph while the queue is not empty
  while (front != rear) {
    // Dequeue the current vertex
    struct Node* current = queue[front++];

    // Visit the current vertex
    printf("%d ", current->data);

    // Enqueue all unvisited adjacent vertices
    struct Node* neighbor = current->next;
    while (neighbor != NULL) {
      int neighborId = neighbor->data;
      if (!visited[neighborId]) {
        visited[neighborId] = 1;
        queue[rear++] = graph->adjList[neighborId];
      }

      neighbor = neighbor->next;
    }
  }

  free(visited);
}



// Function to traverse the graph
void traverseGraph(struct Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));

    // Mark all vertices as not visited
    for (int i = 0; i < graph->numVertices; ++i)
        visited[i] = 0;

    // Traverse the graph starting from each unvisited vertex
    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i])
            traverseGraphDFS(graph, i, visited);
    }

    free(visited);
}

// Function to print the menu options
void printMenu() {
    printf("\n----- Graph Menu -----\n");
    printf("1. Create Graph\n");
    printf("2. Add Edge\n");
    printf("3. Delete Edge\n");
    printf("4. Display Graph\n");
    printf("5. Search Node\n");
    printf("6. Traverse Graph\n");
    printf("7. Exit\n");
}
