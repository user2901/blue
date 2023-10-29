#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 1e9 + 5;

vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        
        int u = top.first;
        int w = top.second;

        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
            
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}

int main() {
    int N, E, T, M;
    cin >> N >> E >> T >> M;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());

    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[v].push_back(make_pair(u, w)); // push như vậy vì ta Dijkstra từ thằng f lên
    }

    Dijkstra(E);
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (dist[i] <= T) cnt++;
    }

    cout << cnt;
    return 0;
}