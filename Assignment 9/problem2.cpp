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
    Graph(int v = 0) {
        vertices = v;
        adj.resize(vertices);
    }

    void createGraph(int v) {
        vertices = v;
        adj.clear();
        adj.resize(vertices);
        cout << " Graph with " << vertices << " vertices created successfully.\n";
    }

    void addEdge(int u, int v, int w) {
        if (u >= vertices || v >= vertices) {
            cout << " Invalid vertex number.\n";
            return;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
        cout << " Edge added between " << u << " and " << v << " (Weight: " << w << ")\n";
    }

    void displayGraph() {
        cout << "\n Adjacency List Representation:\n";
        cout << "---------------------------------\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (auto edge : adj[i])
                cout << "(" << edge.first << ", " << edge.second << ") ";
            cout << endl;
        }
    }

    void primMST() {
        if (vertices == 0) {
            cout << " Graph is empty. Please create and add edges first.\n";
            return;
        }

        vector<int> key(vertices, INT8_MAX);
        vector<int> parent(vertices, -1);
        vector<bool> inMST(vertices, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int start = 0;
        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "\n Minimum Spanning Tree (Prim’s Algorithm):\n";
        cout << "-------------------------------------------\n";
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i << "  (Weight: " << key[i] << ")\n";
            totalWeight += key[i];
        }
        cout << "-------------------------------------------\n";
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    Graph g;
    int choice, v, u, w;

    cout << "=================================================\n";
    cout << "     MENU DRIVEN PROGRAM — PRIM’S ALGORITHM (MST)\n";
    cout << "=================================================\n";

    do {
        cout << "\n------------- MENU -------------\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. Display Graph (Adjacency List)\n";
        cout << "4. Generate MST using Prim’s Algorithm\n";
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
            g.primMST();
            break;

        case 5:
            cout << "Exiting program... Thank you!\n";
            break;

        default:
            cout << "⚠️ Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
