#include <bits/stdc++.h>
#define MAX 505
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
    int N, u, v, w;
    cin >> N;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    
    for (int i = 0; i < N; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int s, Q, x;
    cin >> s;
    Dijkstra(s);
    cin >> Q;

    while (Q--) {
        cin >> x;
        if (dist[x] != INF) cout << dist[x] << "\n";
        else cout << "NO PATH\n";
    }

    return 0;
}