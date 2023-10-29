#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

/* PHÂN TÍCH *
   - giữa 2 đỉnh bất kì luôn có 1 cạnh nối => đồ thị dạng cây (E = V-1)
   - độ dài lớn nhất giữa 2 đỉnh bất kì chính là đường kính của cây
   - đường kính của cây chính là khoảng cách lớn nhất giữa 2 node lá

   - ta DFS từ 1 đỉnh bất kì, node có khoảng cách xa nhất chính là 1 node lá
   - ta DFS 1 lần nữa, node có khoảng cách xa nhất so với node lá này cũng là 1 node lá
    --> double DFS
*/

struct Triad
{
    int v, w;
};

int V, E, leaf;
long long max_dist;
long long dist[MAX];
vector<Triad> graph[MAX];

void DFS(int s) {
    memset(dist, -1, sizeof(dist));
    stack<int> st;
    dist[s] = 0;
    st.push(s);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (Triad &neighbor : graph[u]) {
            int v = neighbor.v;
            int w = neighbor.w;
            
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                st.push(v);

                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    leaf = v;
                }
            }
        }
    }
}

int main() {
    int t, u, v, w;
    cin >> t;

    while (t--) {
        cin >> V;
        E = V - 1;

        for (int i = 0; i <= V; i++) graph[i].clear();

        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            graph[u].push_back((Triad){v, w});
            graph[v].push_back((Triad){u, w});
        }

        max_dist = 0;

        DFS(1);
        DFS(leaf);

        cout << max_dist << "\n";
    }
    
    return 0;
}