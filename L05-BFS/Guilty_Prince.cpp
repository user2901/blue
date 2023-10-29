#include <bits/stdc++.h>
#define MAX 21
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int W, H;
bool visited[MAX][MAX];
char maze[MAX][MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

int BFS(Cell s) {
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    int cnt = 1;

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c]) {
                visited[r][c] = true;
                q.push((Cell){r, c});
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int T; cin >> T;
    Cell s;

    for (int k = 1; k <= T; k++) {
        cin >> W >> H;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> maze[i][j];
                visited[i][j] = false;
                if (maze[i][j] == '@') {
                    s.r = i;
                    s.c = j;
                }
            }
        }

        cout << "Case " << k << ": " << BFS(s) << "\n";
    }
    
    return 0;
}