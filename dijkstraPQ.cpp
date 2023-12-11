#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int destination;
    int weight;
};

// Structure to represent a vertex and its adjacency list
struct Vertex
{
    vector<Edge> adjList;
};

// Function to perform Dijkstra's algorithm using adjacency lists
void dijkstra(vector<Vertex> &graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);  // Array to store the distance from the source
    vector<bool> sptSet(V, false); // Array to track vertices included in the shortest path tree

    // Priority queue to get the minimum distance vertex efficiently
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distance for the source vertex
    dist[src] = 0;

    // Enqueue the source vertex with its distance
    pq.push({0, src});

    while (!pq.empty())
    {
        // Extract the vertex with the minimum distance
        int u = pq.top().second;
        pq.pop();
        // Early stopping condition
        if (dist[u] == INT_MAX)
        {
            // If the minimum distance is still infinity, no relaxation is possible.
            // This means that the remaining vertices are not reachable from the source.
            break;
        }

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update distances of adjacent vertices
        for (const Edge &edge : graph[u].adjList)
        {
            int v = edge.destination;
            int weight = edge.weight;

            // Update dist[v] only if it is not in sptSet, and the total weight
            // of the path from src to v through u is smaller than the current value of dist[v]
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;

                // Enqueue the updated distance and vertex to the priority queue
                pq.push({dist[v], v});
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

int main()
{
    // Number of vertices in the graph
    int V = 9;

    // Create a graph with V vertices
    vector<Vertex> graph(V);

    // Add edges to the graph (example graph from your previous code)
    graph[0].adjList.push_back({1, 4});
    graph[0].adjList.push_back({7, 8});
    graph[1].adjList.push_back({0, 4});
    graph[1].adjList.push_back({2, 8});
    graph[1].adjList.push_back({7, 11});
    // Add edges for the remaining vertices...

    // Call Dijkstra's algorithm with the graph and source vertex
    dijkstra(graph, 0);

    return 0;
}
