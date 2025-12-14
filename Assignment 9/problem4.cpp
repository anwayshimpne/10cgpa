#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

// Dijkstra’s Algorithm Implementation
class Graph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adj; // pair<destination, weight>

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adj.resize(vertices);
    }

    // Function to add an edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});  // Directed edge (for undirected, add reverse also)
    }

    // Dijkstra’s shortest path algorithm
    void dijkstra(int src, int dest) {
        vector<int> dist(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Display shortest distances
        cout << "\n Dijkstras Shortest Path Results:\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < vertices; i++) {
            if (dist[i] == INT_MAX)
                cout << "Vertex " << i << " : Unreachable\n";
            else
                cout << "Vertex " << i << " : " << dist[i] << endl;
        }

        cout << "\nShortest distance from " << src << " to " << dest << " = ";
        if (dist[dest] == INT_MAX)
            cout << "No path exists.\n";
        else
            cout << dist[dest] << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int v, e;
    cout << "=============================================\n";
    cout << " DIJKSTRAS ALGORITHM USING ADJACENCY LIST\n";
    cout << "=============================================\n";

    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v1, w;
        cin >> u >> v1 >> w;
        g.addEdge(u, v1, w);
    }

    int src, dest;
    cout << "Enter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;

    g.dijkstra(src, dest);

    return 0;
}
