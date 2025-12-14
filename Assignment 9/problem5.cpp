#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adj; // Adjacency list

    // Helper function for DFS (recursive)
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v])
            if (!visited[u])
                DFSUtil(u, visited);
    }

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adj.resize(vertices);
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // Display adjacency list
    void displayGraph() {
        cout << "\n Adjacency List Representation:\n";
        cout << "----------------------------------\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int j : adj[i])
                cout << j << " ";
            cout << endl;
        }
    }

    // Perform BFS traversal
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal starting from vertex " << start << ": ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }

    // Perform DFS traversal
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "\nDFS Traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int v, e, u, w, start;

    cout << "=============================================\n";
    cout << "  GRAPH REPRESENTATION USING ADJACENCY LIST\n";
    cout << "         BFS AND DFS TRAVERSALS\n";
    cout << "=============================================\n";

    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> w;
        g.addEdge(u, w);
    }

    g.displayGraph();

    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start;

    g.BFS(start);
    g.DFS(start);

    return 0;
}
