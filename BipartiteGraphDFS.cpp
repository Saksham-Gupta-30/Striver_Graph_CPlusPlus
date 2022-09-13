#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> graph[]);
bool bipartite(int node, vector<int> graph[], vector<int> &color);

int main() {
    int n, m;
    cin >> n >> m;

    //UNDIRECTED GRAPH
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool ans = isBipartite(n, graph);
    cout << boolalpha << ans;

    return 0;
}

bool isBipartite(int V, vector<int> graph[]) {
    vector<int> color(V + 1, -1);
    for (int i = 1; i <= V; i++) {
        if (color[i] == -1)
            if (!bipartite(i, graph, color)) return false;
    }
    return true;
}

bool bipartite(int node, vector<int> graph[], vector<int> &color) {
    if (color[node] == -1) color[node] = 1;

    for (auto it: graph[node]) {
        if (color[it] == -1) {
            color[it] = 1 - color[node];
            if (!bipartite(it, graph, color)) return false;
        } else if (color[it] == color[node]) return false;
    }
    return true;
}