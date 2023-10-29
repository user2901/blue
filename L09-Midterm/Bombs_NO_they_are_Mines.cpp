#include <bits/stdc++.h>
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell
{
    int r, c;
};

int R, C;
vector<vector<int>> graph;

bool isValid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

// ta đánh dấu như sau: graph[i][j] = 0 nếu chưa visit, graph[i][j] = -1 nếu có bom, graph[i][j] = a với a là độ dài đường đi ngắn ngất từ S đến (i, j)
int BFS(Cell s, Cell f) {
    queue<Cell> q;
    q.push(s);
    graph[s.r][s.c] = 1; // nếu cho graph[s.r][s.c] = 0 thì chưa visit -> cho = 1 rồi lấy kết quả -1

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        if (u.r == f.r && u.c == f.c) break;

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (isValid(r, c) && graph[r][c] == 0) {
                graph[r][c] = graph[u.r][u.c] + 1;
                q.push(Cell{r, c});
            }
        }
    }

    return graph[f.r][f.c] - 1;
}

int main() {
    int rows, nbombs, row, col;
    Cell s, f;

    while (true) {
        cin >> R >> C;
        if (R == 0 && C == 0) break;

        cin >> rows;
        graph = vector<vector<int>>(R, vector<int>(C));

        for (int i = 0; i < rows; i++) {
            cin >> row >> nbombs;

            for (int j = 0; j < nbombs; j++) {
                cin >> col;
                graph[row][col] = -1;
            }
        }

        cin >> s.r >> s.c >> f.r >> f.c;
        cout << BFS(s, f) << "\n";
    }

    return 0;
}