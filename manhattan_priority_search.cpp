#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Constants for the grid dimensions
const int GRID_WIDTH = 5;
const int GRID_HEIGHT = 5;

// Struct to represent each vertex in the graph
struct Vertex {
    int x, y;         // Coordinates
    vector<int> adj;   // Adjacency list
    int id;
};

// Function to create the graph
map<int, Vertex> createGraph() {
    map<int, Vertex> graph;
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        for (int j = 0; j < GRID_WIDTH; ++j) {
            int vertexNum = i * GRID_WIDTH + j;
            Vertex vertex;
            vertex.x = j;  // Column number
            vertex.y = i;  // Row number
            vertex.id = vertexNum;

            // Add edges as before
            if (i > 0) vertex.adj.push_back(vertexNum - GRID_WIDTH);
            if (i < GRID_HEIGHT - 1) vertex.adj.push_back(vertexNum + GRID_WIDTH);
            if (j > 0) vertex.adj.push_back(vertexNum - 1);
            if (j < GRID_WIDTH - 1) vertex.adj.push_back(vertexNum + 1);

            // Add the vertex to the graph
            graph[vertexNum] = vertex;
        }
    }
    return graph;
}

// Function to print the graph (for demonstration)
void printGraph(const map<int, Vertex>& graph) {
    for (const auto& pair : graph) {
        cout << "Vertex " << pair.first << " (" << pair.second.x << ", "
             << pair.second.y << ") is connected to: ";
        for (int v : pair.second.adj) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Struct for comparing vertices based on Manhattan distance
struct CompareDistance {
    Vertex target;

    // Constructor to initialize the target
    CompareDistance(const Vertex& targetVertex) {
        target = targetVertex;
    }

    // Comparison function
    bool operator()(const Vertex& a, const Vertex& b) {
        // Calculate the Manhattan distance of a and b from the target
        int distanceA = abs(a.x - target.x) + abs(a.y - target.y);
        int distanceB = abs(b.x - target.x) + abs(b.y - target.y);

        // Lower distance has higher priority
        return distanceA > distanceB;
    }
};

// Priority search algorithm
map<int, int> priority_search(const map<int, Vertex>& G, int src) {
    map<int, bool> marked;
    map<int, int> node_from;
    Vertex targetVertex = G.at(24);
    CompareDistance comp(targetVertex);
    priority_queue<Vertex, vector<Vertex>, CompareDistance> pq(comp);

    // Mark the source node and push it onto the stack
    marked[src] = true;
    pq.push(G.at(src));

    while (!pq.empty()) {
        Vertex v = pq.top();
        pq.pop();

        for (int w : G.at(v.id).adj) {
            if (marked.find(w) == marked.end()) { // If not marked
                node_from[w] = v.id;
                marked[w] = true;
                pq.push(G.at(w));
            }
        }
    }

    return node_from;
}

int main() {
    // Create the graph
    auto graph = createGraph();

    // Print the graph
    printGraph(graph);

    // Perform priority search from the source node (0)
    auto node_from = priority_search(graph, 0);

    // Print the node_from map
    for (const auto& pair : node_from) {
        cout << "Node " << pair.first << " was reached from node " << pair.second
             << endl;
    }

    return 0;
}
