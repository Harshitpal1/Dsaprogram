#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false) {
            if (dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
    }

    return minIndex;
}

void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        int vertex = i;
        int distance = dist[i];
        printf("%d \t %d\n", vertex, distance);
    }
}

void dijkstra(int graph[10][10], int src, int V) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0) {
                if (sptSet[v] == false) {
                    if (dist[u] != INT_MAX) {
                        if (dist[u] + graph[u][v] < dist[v]) {
                            dist[v] = dist[u] + graph[u][v];
                        }
                    }
                }
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int V = 5;

    int graph[10][10] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0},
    };

    printf("Graph (Adjacency Matrix):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int src = 0;

    printf("Dijkstra's Algorithm - Shortest Path from Source Vertex %d:\n", src);

    dijkstra(graph, src, V);

    printf("\n");

    return 0;
}

