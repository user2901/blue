#include <bits/stdc++.h>
#define MAX 251
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int N, M;
int slick[MAX * MAX];
int a[MAX][MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void BFS(Cell s) {
    queue<Cell> q;
    a[s.r][s.c] = 0;
    q.push(s);
    int cnt = 1;

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if (isValid(r, c) && a[r][c] == 1) {
                a[r][c] = 0;
                q.push((Cell){r, c});
                cnt++;
            }
        }
    }
    slick[cnt]++;
}

int main() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a[i][j];
                slick[i*M+j+1] = 0;
            }
        }

        int nSlicks = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 1) {
                    nSlicks++;
                    BFS((Cell){i, j});
                }
            }
        }

        cout << nSlicks << "\n";
        for (int i = 1; i <= N*M; i++) {
            if (slick[i]) cout << i << " " << slick[i] << "\n";
        }
    }

    return 0;
}