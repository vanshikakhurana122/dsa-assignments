#include <iostream>
using namespace std;

#define INF 100000

int n;

class Graph {
public:
    int cost[50][50];

    void inputGraph() {
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter " << n * n
             << " elements for cost adjacency matrix (0 for no edge):\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];
                if (cost[i][j] == 0 && i != j)
                    cost[i][j] = INF;   // treat 0 as no edge
            }
        }
    }

    void kruskalSimple() {
        int comp[50];      // component id of each vertex
        for (int i = 0; i < n; i++)
            comp[i] = i;   // initially, each vertex in its own component

        int edgeCount = 0;
        int totalCost = 0;

        cout << "\nEdges in Minimum Spanning Tree (Kruskal, no DSU):\n";

        // MST must have n-1 edges
        while (edgeCount < n - 1) {
            int minCost = INF;
            int u = -1, v = -1;

            // find cheapest edge that connects two different components
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {   // undirected graph
                    if (cost[i][j] < minCost && comp[i] != comp[j]) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }

            // if we didn't find any such edge, graph is disconnected
            if (u == -1 || v == -1) {
                cout << "Graph is not connected, MST not possible.\n";
                return;
            }

            // include this edge in MST
            cout << u << "-" << v << " (cost=" << minCost << ")\n";
            totalCost += minCost;
            edgeCount++;

            // merge components: all vertices in v's component become u's component
            int oldComp = comp[v];
            int newComp = comp[u];
            for (int k = 0; k < n; k++) {
                if (comp[k] == oldComp)
                    comp[k] = newComp;
            }

            // optional: mark this edge as used (not necessary, but okay)
            // cost[u][v] = cost[v][u] = INF;
        }

        cout << "Total cost of MST = " << totalCost << endl;
    }
};

int main() {
    Graph g;
    g.inputGraph();
    g.kruskalSimple();
    return 0;
}