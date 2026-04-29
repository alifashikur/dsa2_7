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
        adj[v].push_back(u); 
    }
    bool dfsUtil(int src, int dest, vector<bool>& visited) {
        if (src == dest) return true;
        visited[src] = true;
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (dfsUtil(neighbor, dest, visited))
                    return true;
            }
        }
        return false;
    }
    bool pathExists(int src, int dest) {
        vector<bool> visited(V, false);
        return dfsUtil(src, dest, visited);
    }
};
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
   int src = 0, dest = 5;
    if (g.pathExists(src, dest))
        cout << "Path exists between " << src << " and " << dest << endl;
    else
        cout << "No path exists" << endl;

    return 0;
}
