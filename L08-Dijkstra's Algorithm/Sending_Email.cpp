#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
const int INF = 1e9 + 5;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

void Dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        if (u == f) break;

        if (w > dist[u]) continue;

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
    int N, n, m, s, f;
    cin >> N;

    for (int t = 1; t <= N; t++) {
        cin >> n >> m >> s >> f;
        int u, v, w;
        
        for (int i = 0; i < n; i++) graph[i].clear();
        dist = vector<int>(n, INF);

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        Dijkstra(s, f);
        
        cout << "Case #" << t << ": ";
        if (dist[f] == INF) cout << "unreachable\n";
        else cout << dist[f] << "\n";
    }
    
    return 0;
}