#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, int src, vector<int> graph[]);

int main() {
    int n, m;
    cin >> n >> m;

    //UNDIRECTED GRAPH
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    int src;
    cin >> src;

    vector<int> dist;
    dist = shortestPath(n, src, graph);

    cout << "Shortest Distance of Nodes from " << src << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": Distance " << dist[i] << endl;
    }

    return 0;
}

vector<int> shortestPath(int V, int src, vector<int> graph[]) {
    vector<int> dist(V + 1, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it: graph[node]) {
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}