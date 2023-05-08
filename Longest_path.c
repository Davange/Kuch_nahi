/*Write a program to compute longest path from the given
weighted graph using adjacency matrix*/

#include<stdio.h>
#define INF 99999

int max(int a, int b) {
    return (a > b) ? a : b;
}

void longestPath(int graph[][100], int n) {
    int dist[n][n], i, j, k;

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for(k=0;k<n;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j]>dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int longest = -INF;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(dist[i][j] > longest && dist[i][j] != INF) {
                longest = dist[i][j];
            }
        }
    }

    printf("The longest path in the graph is: %d\n", longest);
}

int main() {
    int n, i, j, graph[100][100];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }
    longestPath(graph, n);
    return 0;
}
