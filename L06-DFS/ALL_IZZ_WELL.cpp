#include <bits/stdc++.h>
#define MAX 101
using namespace std;

const string key = "ALLIZZWELL";
const int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};

int R, C;
bool visited[MAX][MAX];
char table[MAX][MAX];
bool found;

bool isValid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void DFS(int sr, int sc, int cnt) {
    if (cnt == key.size()) {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int r = sr + dr[i];
        int c = sc + dc[i];
        
        if (isValid(r, c) && table[r][c] == key[cnt] && !visited[r][c]) {
            visited[r][c] = true;
            DFS(r, c, cnt+1);
            visited[r][c] = false;
        }
    }
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> R >> C;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> table[i][j];
                visited[i][j] = false;
            }
        }

        found = false;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (table[i][j] == key[0] && !found) {
                    DFS(i, j, 1);
                }
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }
    
    return 0;
}