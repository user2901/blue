#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int V, E;
bool visited[MAX];
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
                st.push(v);
            }
        }
    }
}

int main() {
    int t, u, v;
    cin >> t;

    while (t--) {
        cin >> V >> E;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            graph[i].clear();
        }

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cnt++;
                DFS(i);
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}