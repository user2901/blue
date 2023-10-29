#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int N, M;
bool visited[MAX];
vector<int> graph[MAX];

int DFS(int s) {
    memset(visited, false, sizeof(visited));
    stack<int> st;
    visited[s] = true;
    st.push(s);
    int nbombs = 0;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        nbombs++;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
    return nbombs;
}

int main() {
    int u, v;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, DFS(i));

    cout << ans;
    return 0;
}