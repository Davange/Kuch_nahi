/*Write a Program to implement Prims algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to
represent a graph.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 10

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int key[MAX_VERTICES];

void init() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i] = NULL;
        visited[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }
}

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->weight = w;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

int getMinKey() {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prim(int start) {
    key[start] = 0;
    parent[start] = -1;

    for (int i = 0; i < MAX_VERTICES - 1; i++) {
        int u = getMinKey();
        visited[u] = true;

        for (Node* curr = adjList[u]; curr != NULL; curr = curr->next) {
            int v = curr->vertex;
            int w = curr->weight;

            if (!visited[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
}

void printMST() {
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < MAX_VERTICES; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    init();

    // Get input for number of vertices and edges
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Get input for edges
    printf("Enter edges and weights (u v w): ");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    // Perform Prim's algorithm to find minimum spanning tree
    prim(0);

    // Print minimum spanning tree
    printMST();

    return 0;
}