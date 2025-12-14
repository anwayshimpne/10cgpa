#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    // Accept adjacency matrix from user
    void inputGraph() {
        cout << "Enter adjacency matrix (0 if no edge):\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                cin >> adjMatrix[i][j];
        }
    }

    // Display the adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix Representation:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    // Find the vertex with the minimum distance value
    int minDistance(vector<int>& dist, vector<bool>& visited) {
        int min = INT_MAX, minIndex = -1;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    // Dijkstra’s Algorithm
    void dijkstra(int src, int dest) {
        vector<int> dist(vertices, INT_MAX);
        vector<bool> visited(vertices, false);

        dist[src] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited);
            if (u == -1) break; // No more reachable vertices

            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && adjMatrix[u][v] != 0 && dist[u] != INT_MAX
                    && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
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
    int v, src, dest;

    cout << "==============================================\n";
    cout << " DIJKSTRAS ALGORITHM USING ADJACENCY MATRIX\n";
    cout << "==============================================\n";

    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);
    g.inputGraph();
    g.displayMatrix();

    cout << "Enter source vertex: ";
    cin >> src;
    cout << "Enter destination vertex: ";
    cin >> dest;

    g.dijkstra(src, dest);

    return 0;
}
