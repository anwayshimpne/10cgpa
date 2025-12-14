#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an edge
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find) for cycle detection
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
    int vertices;
    vector<vector<pair<int, int>>> adjList;
    vector<Edge> edges;

public:
    Graph(int v = 0) {
        vertices = v;
        adjList.resize(vertices);
    }

    void createGraph(int v) {
        vertices = v;
        adjList.clear();
        edges.clear();
        adjList.resize(vertices);
        cout << " Graph with " << vertices << " vertices created.\n";
    }

    void addEdge(int u, int v, int w) {
        if (u >= vertices || v >= vertices) {
            cout << " Invalid vertex number.\n";
            return;
        }
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // Undirected graph
        edges.push_back({u, v, w});
        cout << " Edge added: (" << u << ", " << v << ") with weight " << w << "\n";
    }

    void displayGraph() {
        cout << "\n Adjacency List Representation:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (auto &edge : adjList[i])
                cout << "(" << edge.first << ", " << edge.second << ") ";
            cout << endl;
        }
    }

    void kruskalMST() {
        if (vertices == 0 || edges.empty()) {
            cout << "⚠️ Graph is empty. Add edges first!\n";
            return;
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DSU dsu(vertices);
        vector<Edge> result;
        int totalWeight = 0;

        cout << "\n Minimum Spanning Tree (Kruskal’s Algorithm):\n";
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
    Graph g;
    int choice, v, u, w;

    cout << "=================================================\n";
    cout << "   MENU DRIVEN PROGRAM — KRUSKALS ALGORITHM (MST)\n";
    cout << "=================================================\n";

    do {
        cout << "\n------------- MENU -------------\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. Display Graph (Adjacency List)\n";
        cout << "4. Generate MST using Kruskals Algorithm\n";
        cout << "5. Exit\n";
        cout << "--------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of vertices: ";
            cin >> v;
            g.createGraph(v);
            break;

        case 2:
            cout << "Enter edge (u v weight): ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
            break;

        case 3:
            g.displayGraph();
            break;

        case 4:
            g.kruskalMST();
            break;

        case 5:
            cout << "Exiting program... Thank you!\n";
            break;

        default:
            cout << " Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
