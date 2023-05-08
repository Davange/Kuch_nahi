/*Write a Program to create a Binary Tree and perform following
nonrecursive operations on it. a. Preorder Traversal b.
Postorder Traversal c. Count total no. of nodes d. Display height
of a tree.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 4950

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* graph[MAX_VERTICES];
Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

void addEdge(int src, int dest, int weight) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph[src];
    graph[src] = newNode;
}

void init(int V) {
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }
}

int find(int i) {
    if (parent[i] == -1) {
        return i;
    }

    return find(parent[i]);
}

void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    parent[xroot] = yroot;
}

int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*) a;
    Edge* edge2 = (Edge*) b;

    return edge1->weight - edge2->weight;
}

void kruskal(int V, int E) {
    qsort(edges, E, sizeof(Edge), compare);

    int i = 0, j = 0;
    while (i < V - 1 && j < E) {
        Edge edge = edges[j++];

        int x = find(edge.src);
        int y = find(edge.dest);

        if (x != y) {
            parent[x] = y;
            addEdge(edge.src, edge.dest, edge.weight);
            addEdge(edge.dest, edge.src, edge.weight);
            i++;
        }
    }
}

void printMST(int V) {
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    // Get input for number of vertices and edges
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Get input for edges and weights
    printf("Enter edges and weights (src dest weight): ");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }

    // Perform Kruskal's algorithm to find minimum spanning tree
    init(V);
    kruskal(V, E);

    // Print minimum spanning tree
    printMST(V);

    return 0;
}

