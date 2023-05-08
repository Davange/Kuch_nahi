/*Write a Program to implement Dijkstra’s algorithm to find
shortest distance between two nodes of a user defined graph.
Use Adjacency List to represent a graph.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct Edge {
    int dest;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    Edge *head;
    int dist;
    int visited;
} Vertex;

Vertex graph[MAX_VERTICES];
int num_vertices;

void add_edge(int src, int dest, int weight) {
    Edge *new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->dest = dest;
    new_edge->weight = weight;
    new_edge->next = graph[src].head;
    graph[src].head = new_edge;
}

void dijkstra(int start, int end) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        graph[i].dist = INF;
        graph[i].visited = 0;
    }
    graph[start].dist = 0;
    while (!graph[end].visited) {
        int u = -1;
        int min_dist = INF;
        for (i = 0; i < num_vertices; i++) {
            if (!graph[i].visited && graph[i].dist < min_dist) {
                u = i;
                min_dist = graph[i].dist;
            }
        }
        if (u == -1) break;
        graph[u].visited = 1;
        Edge *edge = graph[u].head;
        while (edge != NULL) {
            int v = edge->dest;
            int weight = edge->weight;
            if (!graph[v].visited && graph[u].dist + weight < graph[v].dist) {
                graph[v].dist = graph[u].dist + weight;
            }
            edge = edge->next;
        }
    }
}

int main() {
    int num_edges, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    for (i = 0; i < num_edges; i++) {
        int src, dest, weight;
        printf("Enter the source vertex, destination vertex, and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(src, dest, weight);
    }
    int start, end;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Enter the ending vertex: ");
    scanf("%d", &end);
    dijkstra(start, end);
    printf("Shortest distance from vertex %d to vertex %d is %d\n", start, end, graph[end].dist);
    return 0;
}
