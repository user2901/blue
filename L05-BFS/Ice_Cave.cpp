#include <bits/stdc++.h>
#define MAX 501
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int n, m;
char level[MAX][MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool BFS(Cell s, Cell f) {
    queue<Cell> q;
    level[s.r][s.c] = 'X';
    q.push(s);

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if (r == f.r && c == f.c && level[r][c] == 'X') return true;

            if (isValid(r, c) && level[r][c] == '.') {
                level[r][c] = 'X';
                q.push((Cell){r, c});
            }
        }
    }
    return false;
}

int main() {
    Cell s, f;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> level[i][j];
        }
    }

    cin >> s.r >> s.c >> f.r >> f.c;
    s.r -= 1, s.c -= 1, f.r -= 1, f.c -= 1;

    cout << (BFS(s, f) ? "YES" : "NO");
    return 0;
}