#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Graph structure
struct Graph {
    int vertices;
    bool adjMatrix[MAX_SIZE][MAX_SIZE];
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return true;
    else
        return false;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1)
        printf("\nQueue is full!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nQueue is empty!");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to create a graph
void createGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    bool visited[MAX_SIZE] = {false};
    struct Queue* queue = createQueue();

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    struct Graph graph;
    int vertices, edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    createGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d source and destination: ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    BFS(&graph, startVertex);

    return 0;
}

