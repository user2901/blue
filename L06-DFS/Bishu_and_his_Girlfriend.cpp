#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int V, E;
bool visited[MAX];
int dist[MAX];
vector<int> graph[MAX];

void DFS(int s) {
    stack<int> st;
    visited[s] = true;
    st.push(s);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                st.push(v);
            }
        }
    }
}

int main() {
    int Q, u, v;
    cin >> V;
    E = V - 1;

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1);
    int ans = 0, min_dist = MAX;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> u;
        if (dist[u] < min_dist || (dist[u] == min_dist && u < ans)) {
            min_dist = dist[u];
            ans = u;
        }
    }

    cout << ans;
    return 0;
}