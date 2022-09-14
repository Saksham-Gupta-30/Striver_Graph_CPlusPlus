#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    //UNDIRECTED GRAPH
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back(make_pair(v, wt));
        graph[v].push_back(make_pair(u, wt));
    }

    vector<int> parent(n);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    for (int i = 0; i < n - 1; i++) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it: graph[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < n; i++) cout << parent[i] << " - " << i << endl;

    return 0;
}