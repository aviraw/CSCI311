#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

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

map<int, int> bfs_search(const map<int, vector<int>>& G, int src) {
    map<int, bool> marked;
    map<int, int> node_from;
    queue<int> queue;

    // Mark the source node and push it onto the queue
    marked[src] = true;
    queue.push(src);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (int w : G.at(v)) {
            // Using 'at' for safe access to the map
            if (marked.find(w) == marked.end()) {
                // If not marked
                node_from[w] = v;
                marked[w] = true;
                queue.push(w);
            }
        }
    }

    return node_from;
}

stack<int> path_to(map<int, int> node_from, int src, int target) {
    stack<int> path;
    int v = target;

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

    // Perform BFS search starting from node 0
    auto node_from = bfs_search(G, 0);

    // Print the node_from map
    for (const auto& pair : node_from) {
        cout << "Node " << pair.first << " was reached from node " << pair.second << endl;
    }

    return 0;
}
