#include <bits/stdc++.h>
using namespace std;

bool isCycle(int n, vector<int> graph[]);
bool checkForCycle(int node, vector<int> &vis, vector<int> &DFSvis, vector<int> graph[]);

int main() {
    int n, m;
    cin >> n >> m;

    //DIRECTED GRAPH
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    bool ans = isCycle(n, graph);
    cout << boolalpha << ans;

    return 0;
}

bool isCycle(int V, vector<int> graph[]) {
    vector<int> vis(V + 1, 0);
    vector<int> DFSvis(V + 1, 0);
    for (int i = 1; i <= V; i++) {
        if (!vis[i])
            if (checkForCycle(i, vis, DFSvis, graph)) return true;
    }
    return false;
}

bool checkForCycle(int node, vector<int>& vis, vector<int>& DFSvis, vector<int> graph[]) {
    vis[node] = 1;
    DFSvis[node] = 1;
    for (auto it: graph[node]) {
        if (!vis[it]) {
            if (checkForCycle(it, vis, DFSvis, graph)) return true;
        } else if (DFSvis[it] == 1) return true;
    }
    DFSvis[node] = 0;
    return false;
}