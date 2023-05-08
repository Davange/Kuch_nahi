/*Write a Program to implement Kruskals algorithm to find
minimum spanning tree of a user defined graph. Use Adjacency
List to represent a graph.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 10
#define MAX_EDGES 45

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Edge edges[MAX_EDGES];
Subset subsets[MAX_VERTICES];
int parent[MAX_VERTICES];

void init() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
        parent[i] = -1;
    }
}

int find(int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets[i].parent);
    }

    return subsets[i].parent;
}

void unionSet(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
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
            parent[edge.dest] = edge.src;
            unionSet(x, y);
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
    init();
    kruskal(V, E);

    // Print minimum spanning tree
    printMST(V);

    return 0;
}