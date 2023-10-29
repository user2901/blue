#include <bits/stdc++.h>
#define MAX 21
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int n, m;
bool visited[MAX][MAX];
char maze[MAX][MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

bool BFS(Cell s, Cell f) {
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        if (u.r == f.r && u.c == f.c) return true;

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c]) {
                visited[r][c] = true;
                q.push((Cell){r, c});
            }
        }
    }
    return false;
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
                visited[i][j] = false;
            }
        }

        vector<Cell> entrance;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == '.' && (i == 0 || i == m-1 || j == 0 || j == n-1)) {
                    entrance.push_back((Cell){i, j});
                }
            }
        }

        if (entrance.size() != 2) cout << "invalid\n";
        else {
            Cell s = entrance[0];
            Cell f = entrance[1];
            cout << (BFS(s, f) ? "valid\n" : "invalid\n");
        }
    }

    return 0;
}