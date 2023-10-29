#include <bits/stdc++.h>
#define MAX 51
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int n, m, k;
bool visited[MAX][MAX];
char table[MAX][MAX];

struct Cell
{
    int r, c;
};

vector<vector<Cell>> lakes;

bool sortBySize(const vector<Cell> &a, const vector<Cell> &b) {
    return a.size() < b.size();
}

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool onBorder(int r, int c) {
    return r == 0 || c == 0 || r == n - 1 || c == m - 1;
}

void DFS(Cell s) {
    stack<Cell> st;
    visited[s.r][s.c] = true;
    st.push(s);

    bool isOcean = false;
    vector<Cell> temp;

    while (!st.empty()) {
        Cell u = st.top();
        temp.push_back(u);
        st.pop();

        if (onBorder(u.r, u.c)) isOcean = true;

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            
            if (isValid(r, c) && table[r][c] == '.' && !visited[r][c]) {
                visited[r][c] = true;
                st.push((Cell){r, c});
            }
        }
    }

    if (!isOcean) lakes.push_back(temp);
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && table[i][j] == '.') {
                DFS((Cell){i, j});
            }
        }
    }

    sort(lakes.begin(), lakes.end(), sortBySize);
    int sum_cell = 0;

    for (int i = 0; i < lakes.size() - k; i++) {
        sum_cell += lakes[i].size();
        for (int j = 0; j < lakes[i].size(); j++) {
            Cell u = lakes[i][j];
            table[u.r][u.c] = '*';
        }
    }

    cout << sum_cell << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << table[i][j];
        cout << "\n";
    }
    return 0;
}