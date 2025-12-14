#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find) class
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

        if (rootX == rootY)
            return;

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

// Kruskal’s Algorithm Implementation
class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<Edge> edges;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    // Accept adjacency matrix from user
    void inputGraph() {
        cout << "Enter adjacency matrix (0 for no edge):\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cin >> adjMatrix[i][j];
                if (adjMatrix[i][j] != 0 && i < j) {
                    Edge e = {i, j, adjMatrix[i][j]};
                    edges.push_back(e);
                }
            }
        }
    }

    // Display adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix Representation:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    // Kruskal’s Algorithm to find MST
    void kruskalMST() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DSU dsu(vertices);
        vector<Edge> result;
        int totalWeight = 0;

        for (auto &edge : edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                result.push_back(edge);
                totalWeight += edge.weight;
            }
        }

        cout << "\n Minimum Spanning Tree (Kruskal s Algorithm):\n";
        cout << "---------------------------------------------\n";
        for (auto &edge : result)
            cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";

        cout << "---------------------------------------------\n";
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int v;
    cout << "=============================================\n";
    cout << "   KRUSKAL S ALGORITHM USING ADJACENCY MATRIX\n";
    cout << "=============================================\n";

    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);
    g.inputGraph();
    g.displayMatrix();
    g.kruskalMST();

    return 0;
}
