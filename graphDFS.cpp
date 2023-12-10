#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

// Function to create a directed graph represented as an adjacency list
map<int, vector<int>> createGraph() {
    return map<int, vector<int>>{
        {0, {1, 3}},
        {1, {2, 3, 4}},
        {2, {5}},
        {3, {1}},
        {4, {1, 5}},
        {5, {}}
    };
}

// Depth-First Search (DFS) function
map<int, int> dfs_search(const map<int, vector<int>>& G, int src) {
    // To track visited nodes
    map<int, bool> marked;
    // To store the parent node from which each node is reached
    map<int, int> node_from;
    // Stack for DFS traversal
    stack<int> stack;

    // Mark the source node and push it onto the stack
    marked[src] = true;
    stack.push(src);

    // Perform DFS
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        // Iterate through adjacent nodes of the current node
        for (int w : G.at(v)) {
            // If the adjacent node is not marked, mark it, set the parent, and push it onto the stack
            if (marked.find(w) == marked.end()) {
                node_from[w] = v;
                marked[w] = true;
                stack.push(w);
            }
        }
    }

    return node_from;
}

// Function to reconstruct the path from the source to the target node
stack<int> path_to(map<int, int> node_from, int src, int target) {
    stack<int> path;
    int v = target;

    // Reconstruct the path by backtracking from the target to the source
    while (v != src) {
        path.push(v);
        v = node_from.at(v);
    }
    path.push(src);

    return path;
}

int main() {
    // Create a graph
    auto G = createGraph();

    // Perform DFS search starting from node 0
    auto node_from = dfs_search(G, 0);

    // Print the node_from map
    cout << "DFS traversal results:" << endl;
    for (const auto& pair : node_from) {
        cout << "Node " << pair.first << " was reached from node " << pair.second << endl;
    }

    // Uncomment the following lines to print the path from node 2 to node 4
    stack<int> path = path_to(node_from, 2, 4);
    cout << "Path from node 2 to node 4: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}
