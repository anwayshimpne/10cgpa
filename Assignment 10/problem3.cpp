#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adj; // pair<vertex, weight>

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adj.resize(vertices);
    }

    // Function to add edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    // Prim’s Algorithm
    void primMST() {
        vector<int> key(vertices, INT8_MAX);     // Minimum weight edge for each vertex
        vector<int> parent(vertices, -1);       // To store MST
        vector<bool> inMST(vertices, false);    // Included in MST or not

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int start = 0;
        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "\n Minimum Spanning Tree (Prims Algorithm):\n";
        cout << "--------------------------------------------\n";
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i << "  (Weight: " << key[i] << ")\n";
            totalWeight += key[i];
        }
        cout << "--------------------------------------------\n";
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int v, e;
    cout << "==============================================\n";
    cout << "   PRIMS ALGORITHM USING ADJACENCY LIST\n";
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

    g.primMST();

    return 0;
}
