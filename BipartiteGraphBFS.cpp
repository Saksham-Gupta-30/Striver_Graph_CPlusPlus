#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> graph[]);
bool bipartite(int V, vector<int> &color, vector<int> graph[]);

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

    bool ans = isCycle(n, graph);
    cout << boolalpha << ans;

    return 0;
}

bool isCycle(int V, vector<int> graph[]) {
    vector<int> color(V + 1, -1);
    for (int i = 1; i <= V; i++) {
        if (color[i] == -1) {
            if (!bipartite(i, color, graph)) return false;
        }
    }
    return true;
}

bool bipartite(int node, vector<int>& color, vector<int> graph[]) {
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (auto it: graph[i]) {
            if (color[it] == -1) {
                color[it] = 1 - color[i];
                q.push(it);
            } else if (color[it] == color[i]) return false;
        }
    }
    return true;
}