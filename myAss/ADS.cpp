#include <iostream>
using namespace std;
#define MAX_EDGES 100
#define MAX_VERTICES 100
// Class to represent an Edge
class Edge
{
public:
    int src, dest, weight;
};
// Disjoint Set (Union-Find) with Path Compression & Union by Rank
class DisjointSet
{
private:
    int parent[MAX_VERTICES], rank[MAX_VERTICES];

public:
    // Initialize n elements with themselves as parents
    void initialize(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    // Find function with Path Compression
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    // Union function with Union by Rank
    void unionByRank(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++; // Increase rank if both were equal
            }
        }
    }
};
// Function to manually sort edges by weight using Bubble Sort
void sortEdges(Edge edges[], int edgeCount)
{
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
// Kruskal's Algorithm
void kruskalMST(Edge edges[], int V, int E)
{
    // Step 1: Sort all edges by weight
    sortEdges(edges, E);
    DisjointSet ds;
    ds.initialize(V);
    Edge mst[MAX_VERTICES]; // To store MST edges
    int mstSize = 0;
    // Step 2: Process edges in sorted order
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        // Check if adding this edge creates a cycle
        if (ds.find(u) != ds.find(v))
        {
            ds.unionByRank(u, v);
            mst[mstSize++] = edges[i];
            // If we have (V-1) edges in MST, we stop
            if (mstSize == V - 1)
                break;
        }
    }
    // Step 3: Print the MST
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 0; i < mstSize; i++)
    {
        cout << mst[i].src << " - " << mst[i].dest << " : " << mst[i].weight << endl;
    }
}
// Driver Code
int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    Edge edges[MAX_EDGES];
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    kruskalMST(edges, V, E);
    return 0;
}