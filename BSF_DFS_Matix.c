/*Write a Program to accept a graph from user and represent it
with Adjacency Matrix and perform BFS and DFS traversals on
it*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void init() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = false;
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void bfs(int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < MAX_VERTICES; i++) {
            if (adjMatrix[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void dfs(int start) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
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
    printf("Enter edges (u v): ");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Perform BFS and DFS traversals
    printf("BFS traversal: ");
    bfs(0);
    printf("\n");

    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    printf("DFS traversal: ");
    dfs(0);
    printf("\n");

    return 0;
}