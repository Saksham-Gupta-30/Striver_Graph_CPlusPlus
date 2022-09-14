#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort(int V, vector<int> graph[]);

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
    vector<int> ans;
    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
        for (auto it: graph[i])
            indegree[it]++;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it: graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return ans;
}