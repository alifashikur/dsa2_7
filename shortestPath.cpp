#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }
    void shortestPath(int src, int dest) {
        vector<int> dist(V, -1), parent(V, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }
        if (dist[dest] == -1) {
            cout << "No path exists\n";
            return;
        }
        cout << "Shortest path length: " << dist[dest] << endl;
        vector<int> path;
        for (int v = dest; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path) cout << v << " ";
        cout << endl;
    }
};
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.shortestPath(0, 5);
    return 0;
}
