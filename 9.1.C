#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
};

// Function to find the parent of a vertex using Union-Find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    subsets[xroot].parent = yroot;
}

// Kruskal's algorithm to find MST
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // Stores the MST
    struct Subset subsets[V];

    for (int v = 0; v < V; ++v)
        {subsets[v].parent = v;}

    // Sort edges in ascending order of weight
    for (int i = 0; i < E - 1; ++i) {
        for (int j = 0; j < E - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int e = 0; 
    int i = 0; 

    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edges in the MST:\n");
    for (int j = 0; j < e; ++j)
        printf("%d - %d: %d\n", result[j].src, result[j].dest, result[j].weight);
}

int main() {
    int V = 4; 
    int E = 5;
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {2, 3, 4},
        {3, 1, 15}, {0, 3, 5}
    };

    kruskal(edges, V, E);
    return 0;
}
