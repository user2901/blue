#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 5;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);

int getIndex(string name, vector<string> cities) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == name) return i;
    }
    return -1;
}

/*
    2 bài Mice and Maze với Travelling Cost ko cần struct option vì ta sẽ Dijkstra cho đến khi pq rỗng, ko có điều kiện dừng
    như bài này nên ko cần struct option (vì nó sẽ Dijkstra và khi gặp w + neighbor.second < dist[neighbor.first] nó sẽ tự cập nhật).
    Còn bài này có điều kiện dừng nên ta ưu tiên thằng second trong pq hơn
*/
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
    int T, N, Q;
    vector<string> cities;
    int neighbors, u, v, w;
    string name, sCity, fCity;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) graph[i].clear();
        cities.clear();

        for (int u = 1; u <= N; u++) {
            cin >> name >> neighbors;
            cities.push_back(name);

            for (int i = 0; i < neighbors; i++) {
                cin >> v >> w;
                graph[u].push_back(make_pair(v, w));
            }
        }

        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> sCity >> fCity;
            int s = getIndex(sCity, cities) + 1;
            int f = getIndex(fCity, cities) + 1;
            dist = vector<int>(N+1, INF);
            Dijkstra(s, f);
            cout << dist[f] << "\n";
        }
    }

    return 0;
}