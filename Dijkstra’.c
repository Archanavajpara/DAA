// dijikshtra
#include <stdio.h>
#define Max 100

void dijkstra(int graph[Max][Max], int vertex, int source) {
    int dist[Max];
    int visited[Max] = {0};

    for (int i = 0; i < vertex; i++) {
        dist[i] = 1e9; // Initialize distances to infinity
    }
    dist[source] = 0;

    for (int count = 0; count < vertex - 1; count++) {
        int minDist = 1e9, minIndex;

        for (int v = 0; v < vertex; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < vertex; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != 1e9 &&
                dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertex; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void main() {
    int vertex, edge;
    scanf("%d %d", &vertex, &edge);

    int graph[Max][Max] = {0};

    for (int i = 0; i < edge; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; // For undirected graph
    }

    int source;
    scanf("%d", &source);
    dijkstra(graph, vertex, source);
}
