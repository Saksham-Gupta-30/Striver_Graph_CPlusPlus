#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> graph[]);

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

    bool ans = isCyclic(n, graph);
    cout << boolalpha << ans;

    return 0;
}

bool isCyclic(int V, vector<int> graph[]) {
    vector<int> indegree(V + 1, 0);
    queue<int> q;

    for (int i = 1; i <= V; i++)
        for (auto it: graph[i])
            indegree[it]++;

    for (int i = 1; i <= V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (auto it: graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    if (count == V) return false;
    return true;
}