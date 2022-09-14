#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> &vis, stack<int> &st, vector<int> graph[]);
vector<int> shortestPath(int V, int src, vector<pair<int, int>> graph[]);

int main() {
    int n, m;
    cin >> n >> m;

    //DIRECTED GRAPH
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back({v, wt});
    }

    vector<int> dist;
    dist = shortestPath(n, 0, graph);

    cout << "Shortest Distance of Nodes from " << 0 << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": Distance " << dist[i] << endl;
    }

    return 0;
}

void topoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> graph[]) {
    vis[node] = 1;
    for (auto it: graph[node]) {
        if (!vis[it.first])
            topoSort(it.first, vis, st, graph);
    }
    st.push(node);
}

vector<int> shortestPath(int V, int src, vector<pair<int, int>> graph[]) {
    vector<int> dist(V, 1e9);
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!vis[i])
            topoSort(i, vis, st, graph);

    dist[src] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (auto it: graph[node]) {
            if (dist[node] + it.second < dist[it.first])
                dist[it.first] = dist[node] + it.second;
        }
    }

    return dist;
}