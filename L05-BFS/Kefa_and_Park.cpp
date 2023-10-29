#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n, m;
int a[MAX], cat[MAX];
bool visited[MAX];
vector<int> graph[MAX];

int BFS(int s) {
    int nrestaurants = 0;
    queue<int> q;
    visited[s] = true;
    q.push(s);

    cat[s] = (a[s] == 1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            
            if (!visited[v]) {
                visited[v] = true;

                if (a[v] == 1) {
                    cat[v] = cat[u] + 1;
                }

                if (cat[v] <= m) {
                    if (graph[v].size() == 1) { // kiểm tra số đỉnh kề với v là 1 (đồng nghĩa v là nút lá) -> tăng đếm lên 1
                        nrestaurants++;
                    }
                    else { // nguợc lại thì đẩy đỉnh v vào hàng đợi
                        q.push(v);
                    }
                }
            }
        }
    }
    return nrestaurants;
}

int main() {
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << BFS(1);
    return 0;
}