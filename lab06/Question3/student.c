#include "graph.h"

// Description

// Check whether the graph contains a triangle. A triangle is a set of three nodes that are all connected to each other. 
// The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int has_triangle(Graph* g) {
    for (int u = 0; u < MAX_NODES; u++) {
        for (int v = 0; v < MAX_NODES; v++) {
            for (int w = 0; w < MAX_NODES; w++) {
                if (g->adj[u][v] == 1 && g->adj[v][w] == 1 && g->adj[u][w] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}