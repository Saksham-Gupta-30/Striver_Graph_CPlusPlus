#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(int V, vector<int> graph[]);
void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> graph[]);

int main() {
    int n, m;
    cin >> n >> m;

    //DIRECTED GRAPH
    vector<int> graph[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    vector<int> ans;
    ans = topological_sort(n, graph);

    for (auto it: ans) cout << it << " ";

    return 0;
}

vector<int> topological_sort(int V, vector<int> graph[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            dfs(i, vis, st, graph);
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> graph[]) {
    vis[node] = 1;
    for (auto it: graph[node]) {
        if (!vis[it])
            dfs(it, vis, st, graph);
    }
    st.push(node);
}