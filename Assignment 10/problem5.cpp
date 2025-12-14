#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
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
        adj[u].push_back({v, w});  // Directed graph (for undirected, add both)
        // adj[v].push_back({u, w}); // Uncomment this line for undirected graph
    }

    // Display adjacency list
    void displayGraph() {
        cout << "\n Adjacency List Representation:\n";
        cout << "----------------------------------\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (auto edge : adj[i])
                cout << "(" << edge.first << ", " << edge.second << ") ";
            cout << endl;
        }
    }

    // Dijkstra’s Algorithm
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
    int v, e, src, dest;
    cout << "==============================================\n";
    cout << "   DIJKSTRA S ALGORITHM USING ADJACENCY LIST\n";
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

    cout << "\nEnter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;

    g.dijkstra(src, dest);

    return 0;
}
