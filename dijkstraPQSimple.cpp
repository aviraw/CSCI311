#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Edge
{
    int destination;
    int weight;
};

struct Vertex
{
    int dist = INT_MAX;
    Vertex *pred = nullptr;
    vector<Edge> adjList;
};

struct CompareDist
{
    bool operator()(const Vertex *v1, const Vertex *v2) const
    {
        return v1->dist > v2->dist;
    }
};

void relax(Vertex *u, Vertex *v, int weight, priority_queue<Vertex *, vector<Vertex *>, CompareDist> &pq)
{
    if (u->dist != INT_MAX && u->dist + weight < v->dist)
    {
        v->dist = u->dist + weight;
        v->pred = u;
        pq.push(v);
    }
}

void dijkstra(vector<Vertex> &graph, Vertex *s)
{
    priority_queue<Vertex *, vector<Vertex *>, CompareDist> pq;

    s->dist = 0;
    pq.push(s);

    while (!pq.empty())
    {
        Vertex *u = pq.top();
        pq.pop();

        // Early stopping condition
        if (u->dist == INT_MAX)
        {
            // If the minimum distance is still infinity, no relaxation is possible.
            // This means that the remaining vertices are not reachable from the source.
            break;
        }
        
        for (const Edge &edge : u->adjList)
        {
            Vertex *v = &graph[edge.destination];
            relax(u, v, edge.weight, pq);
        }
    }
}

int main()
{
    int V = 9;
    vector<Vertex> graph(V);

    // Add edges to the graph (example graph from your previous code)
    graph[0].adjList = {{1, 4}, {7, 8}};
    graph[1].adjList = {{0, 4}, {2, 8}, {7, 11}};
    // Add edges for the remaining vertices...

    Vertex *sourceVertex = &graph[0];

    dijkstra(graph, sourceVertex);

    cout << "Vertex \t Distance from Source \t Predecessor\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << graph[i].dist << " \t\t\t" << (graph[i].pred ? graph[i].pred - &graph[0] : -1) << endl;

    return 0;
}
