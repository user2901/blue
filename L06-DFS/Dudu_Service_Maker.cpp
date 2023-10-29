#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

/*
    in[i]: check xem i có nằm trên đường đi từ gốc DFS đến đỉnh u đang xét ko, nếu có thì -> tạo vòng lặp khi duyệt DFS(u) xong, 
    thì lúc trở về đỉnh cha của u, chắc chắn u ko nằm trên đường đi từ gốc đến cha của u
    -> cần gán lại in[u] = false trước khi thoát khỏi DFS(u)
*/
int N, M;
bool visited[MAX], in[MAX]; 
vector<int> graph[MAX];
bool ok;

void DFS(int s) {
    visited[s] = true;
    in[s] = true;

    for (int i = 0; i < graph[s].size(); i++) {
        int v = graph[s][i];
        
        if (in[v]) ok = true;

        if (!visited[v]) DFS(v);
    }

    in[s] = false;
}

int main() {
    int T, u, v;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            graph[i].clear();
            visited[i] = false;
            in[i] = false;
        }

        for (int i = 0; i < M; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
        }

        ok = false;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) DFS(i);
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    
    return 0;
}