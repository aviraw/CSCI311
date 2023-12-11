#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int V, int E, int src) {
    // Initialize distance array
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax edges repeatedly
    for (int i = 1; i <= V - 1; i++) {
        bool relaxed = false;  // Flag to check if any relaxation occurred in this pass

        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            // Relaxation step
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                relaxed = true;  // Relaxation occurred
            }
        }

        // If no relaxation occurred, break early
        if (!relaxed) {
            cout << "No further relaxation possible. Stopping early.\n";
            break;
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        // Check for negative weight cycle
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle!\n";
            return;
        }
    }

    // Print the distance array
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Example graph represented by edge list
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int sourceVertex = 0;

    bellmanFord(edges, V, E, sourceVertex);

    return 0;
}
