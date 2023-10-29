#include <bits/stdc++.h>
#define MAX 51
using namespace std;

const int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};

int H, W;
int visited[MAX][MAX];
char table[MAX][MAX];
int ans;

bool isValid(int r, int c) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

int DFS(int sr, int sc) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        int r = sr + dr[i];
        int c = sc + dc[i];
        
        if (isValid(r, c) && table[r][c] - table[sr][sc] == 1 && visited[r][c] == 0) {
            DFS(r, c);
            cnt = max(cnt, visited[r][c]);
        }
    }

    visited[sr][sc] = cnt + 1;
    return visited[sr][sc];
}

int main() {
    int T = 1;

    while (true) {
        cin >> H >> W;
        if (W == 0 && H == 0) break;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> table[i][j];
                visited[i][j] = 0;
            }
        }

        ans = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (table[i][j] == 'A') {
                    ans = max(ans, DFS(i, j));
                }
            }
        }

        cout << "Case " << T++ << ": " << ans << "\n";
    }
    
    return 0;
}