#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// Graph Class
class Graph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;
    vector<Edge> edges;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    // Add edge (undirected graph)
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    // Display adjacency list
    void displayGraph() {
        cout << "\nAdjacency List Representation:\n";
        cout << "----------------------------------\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (auto edge : adjList[i])
                cout << "(" << edge.first << ", " << edge.second << ") ";
            cout << endl;
        }
    }

    // Kruskal’s Algorithm for MST
    void kruskalMST() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DSU dsu(vertices);
        vector<Edge> result;
        int totalWeight = 0;

        cout << "\n Minimum Spanning Tree (Kruskals Algorithm):\n";
        cout << "---------------------------------------------\n";

        for (auto &edge : edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                result.push_back(edge);
                totalWeight += edge.weight;
                cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
            }
        }

        cout << "---------------------------------------------\n";
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int v, e;
    cout << "==============================================\n";
    cout << "   KRUSKALS ALGORITHM USING ADJACENCY LIST\n";
    cout << "==============================================\n";

    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v1, w;
        cin >> u >> v1 >> w;
        g.addEdge(u, v1, w);
    }

    g.displayGraph();
    g.kruskalMST();

    return 0;
}
