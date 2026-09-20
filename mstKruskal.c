#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int root_u = findParent(parent, u);
    int root_v = findParent(parent, v);

    if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
    } else if (rank[root_u] > rank[root_v]) {
        parent[root_v] = root_u;
    } else {
        parent[root_v] = root_u;
        rank[root_u]++;
    }
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    
    qsort(graph->edges, E, sizeof(struct Edge), compareEdges);

    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mst_weight = 0;
    int edges_count = 0;

    printf("Edges in Minimum Spanning Tree (Kruskal):\n");
    for (int i = 0; i < E; i++) {
        int u = graph->edges[i].u;
        int v = graph->edges[i].v;
        int w = graph->edges[i].weight;

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSets(parent, rank, u, v);
            printf("%d - %d : %d\n", u, v, w);
            mst_weight += w;
            edges_count++;
            if (edges_count == V - 1)
                break;
        }
    }
    printf("Total Weight of MST = %d\n", mst_weight);
}

int main() {
    int V = 4, E = 5;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));

  
    graph->edges[0].u = 0; graph->edges[0].v = 1; graph->edges[0].weight = 10;
    
    graph->edges[1].u = 0; graph->edges[1].v = 2; graph->edges[1].weight = 6;
  
    graph->edges[2].u = 0; graph->edges[2].v = 3; graph->edges[2].weight = 5;

    graph->edges[3].u = 1; graph->edges[3].v = 3; graph->edges[3].weight = 15;
   
    graph->edges[4].u = 2; graph->edges[4].v = 3; graph->edges[4].weight = 4;

    kruskalMST(graph);

    free(graph->edges);
    free(graph);
    return 0;
}