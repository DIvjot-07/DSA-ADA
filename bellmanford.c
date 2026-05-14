#include <stdio.h>
#define N 10
#define INF 99999

struct Edge {
    int src, dest, wt;
} edges[N * N];

int dist[N];

void bellmanFord(int src, int n, int e) {
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].wt;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < e; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].wt;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected!\n");
            return;
        }
    }

    printf("\nVertex  Distance\n");

    for (int i = 0; i < n; i++)
        printf("  %d  ->  %d\n", i, dist[i]);
}

int main() {
    int n, e, src;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (src dest weight):\n");

    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].wt);

    printf("Enter source: ");
    scanf("%d", &src);

    bellmanFord(src, n, e);

    return 0;
}
