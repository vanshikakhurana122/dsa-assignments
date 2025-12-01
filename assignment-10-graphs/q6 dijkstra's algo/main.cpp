#include <iostream>
using namespace std;

#define INF 100000

int n;

class Graph {
public:
    int cost[50][50];

    // input graph
    void inputGraph() {
        cout << "enter number of vertices: ";
        cin >> n;

        cout << "enter " << n * n
             << " elements for cost adjacency matrix (0 for no edge): " << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];
                if (cost[i][j] == 0 && i != j)
                    cost[i][j] = INF;   // no edge
            }
        }
    }

    // Dijkstra's algorithm: single source shortest paths
    void dijkstra(int src) {
        int dist[50];    // shortest distance from src
        int parent[50];  // to store shortest path tree
        bool visited[50];

        // initialization
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[src] = 0;
        parent[src] = -1;

        // find shortest path to all vertices
        for (int count = 0; count < n - 1; count++) {
            int u = -1;
            int minDist = INF;

            // pick vertex with minimum dist[] not yet visited
            for (int v = 0; v < n; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }

            if (u == -1)  // no reachable vertex left
                break;

            visited[u] = true;

            // relax edges from u
            for (int v = 0; v < n; v++) {
                if (!visited[v] && cost[u][v] < INF) { // there is an edge
                    if (dist[u] + cost[u][v] < dist[v]) {
                        dist[v] = dist[u] + cost[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        // print result
        cout << endl << "Shortest distances from source vertex " << src << ":" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INF)
                cout << "unreachable";
            else
                cout << dist[i];
            cout << endl;
        }

        // optional: print shortest-path tree (like MST style)
        cout << endl << "Shortest Path Tree edges (parent -> vertex):" << endl;
        for (int i = 0; i < n; i++) {
            if (i != src && parent[i] != -1) {
                cout << parent[i] << " -> " << i
                     << "  (edge cost = " << cost[parent[i]][i] << ")" << endl;
            }
        }
    }
};

int main() {
    Graph g;
    g.inputGraph();

    int src;
    cout << "enter source vertex (0 to " << n-1 << "): ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}