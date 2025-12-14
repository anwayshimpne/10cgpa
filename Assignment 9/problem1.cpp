#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<bool> visited;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        visited.resize(vertices, false);
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
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

    // BFS traversal
    void BFS(int start) {
        fill(visited.begin(), visited.end(), false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal starting from vertex " << start << ": ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[node][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // DFS traversal
    void DFSUtil(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[node][i] && !visited[i])
                DFSUtil(i);
        }
    }

    void DFS(int start) {
        fill(visited.begin(), visited.end(), false);
        cout << "\nDFS Traversal starting from vertex " << start << ": ";
        DFSUtil(start);
        cout << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    int v, e, u, w, start;
    cout << "============================================\n";
    cout << " GRAPH REPRESENTATION USING ADJACENCY MATRIX\n";
    cout << "============================================\n";

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

    g.displayMatrix();

    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start;

    g.BFS(start);
    g.DFS(start);

    return 0;
}
