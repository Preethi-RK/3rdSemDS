#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Graph structure
struct Graph {
    int vertices;
    bool adjMatrix[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE];
};

// Function to create a graph
void createGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = false;
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

// Function to perform DFS traversal
void DFS(struct Graph* graph, int vertex, int* count) {
    (*count)++;
    graph->visited[vertex] = true;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] && !graph->visited[i]) {
            DFS(graph, i, count);
        }
    }
}

int main() {
    struct Graph graph;
    int vertices, edges;

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

    int count = 0;
    printf("DFS Traversal: ");
    DFS(&graph, 0, &count); // Starting DFS from vertex 0

    if (count == vertices)
        printf("\nGraph is connected.\n");
    else
        printf("\nGraph is not connected.\n");

    return 0;
}

