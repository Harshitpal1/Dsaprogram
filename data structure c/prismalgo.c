#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[10][10], int V) {
    printf("Edge \tWeight\n");

    int totalWeight = 0;

    for (int i = 1; i < V; i++) {
        int from = parent[i];
        int to = i;
        int weight = graph[i][parent[i]];

        printf("%d - %d \t%d\n", from, to, weight);

        totalWeight += weight;
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

void primMST(int graph[10][10], int V) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && mstSet[v] == false) {
                if (graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V = 5;

    int graph[10][10] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    printf("Graph representation (Adjacency Matrix):\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");

    primMST(graph, V);

    printf("\n");

    return 0;
}
