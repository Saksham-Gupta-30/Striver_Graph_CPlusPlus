// Shortest Path In Undirected Graph
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, int src, vector<pair<int, int>> graph[]);

int main() {
    int n, m;
    cin >> n >> m;

    //UNDIRECTED GRAPH
    vector<pair<int, int>> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    int src;
    cin >> src;

    vector<int> ans;
    ans = dijkstra(n, src, graph);

    cout << "Distance of Nodes from source " << src << endl;
    for (int i = 1; i <= n; i++) cout << "Node " << i << ": Distance " << ans[i] << endl;

    return 0;
}

vector<int> dijkstra(int V, int src, vector<pair<int, int>> graph[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(V + 1, INT_MAX);

    distance[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (it = graph[prev].begin(); it != graph[prev].end(); it++) {
            int next = it->first;
            int nextDist = it->second;
            if (dist + nextDist < distance[next]) {
                distance[next] = distance[prev] + nextDist;
                pq.push(make_pair(distance[next], next));
            }
        }
    }

    return distance;
}