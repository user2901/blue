#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 5;

/*
   ** HƯỚNG DẪN GIẢI:
    - Đầu tiên gắn toàn bộ đường đi 1 chiều vào đồ thị sau đó lần lượt gắn từng đường đi 2 chiều vào, nếu đường nào cho ra đường đi
ngắn nhất thì chọn đó là kết quả cuối cùng.
    - Lưu ý: để làm dc việc này thì mỗi lần gắn đường đi 2 chiều vào bạn phải chạy lại Dijkstra, việc này sẽ làm TLE.
    -> Bạn phải cải thiện thuật toán Dijkstra và cải thiện luôn việc ko thể gọi Dijkstra mỗi lần gắn đường đi 2 chiều mới = cách như sau:

        + Tính Dijkstra từ s -> t và tính chiều ngược lại t -> s (gọi Dijkstra 2 lần)
        + Sau khi chạy Dijkstra ta có:
            distS[u]: tìm đường đi từ đỉnh s đến đỉnh u
            distT[v]: tìm đường đi từ đỉnh v đến đỉnh t
        + Gắn từng đường đi 2 chiều vào, lúc này dùng công thức bên dưới, công thức này giống như việc gọi lại Dijkstra mỗi
    lần gắn đường đi 2 chiều vào
        + Sau khi gắn w vào, nếu tổng này nhỏ hơn đường đi hiện tại đang có thì nó chính là đường đi ngắn nhất
        + Công thức:
                int a = distS[u] + w + distT[v]
                int b = distS[v] + w + distT[u]
                result = min(result, min(a, b))
*/


vector<pair<int, int>> graphS[MAX], graphT[MAX];
int distS[MAX], distT[MAX];

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};


void Dijkstra(int s, int dist[], vector<pair<int, int>> (&graph)[MAX]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.first;
        int w = top.second;

        if (w > dist[u]) continue;

        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];

            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T, n, m, k, s, t, u, v, w;
    cin >> T;

    while (T--) {
        cin >> n >> m >> k >> s >> t;

        for (int i = 1; i <= n; i++) {
            graphS[i].clear();
            graphT[i].clear();
            distS[i] = INF;
            distT[i] = INF;
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graphS[u].push_back(make_pair(v, w));
            graphT[v].push_back(make_pair(u, w));
        }

        Dijkstra(s, distS, graphS);
        Dijkstra(t, distT, graphT);
        int res = distS[t];

        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            int a = distS[u] + w + distT[v];
            int b = distS[v] + w + distT[u];
            res = min(res, min(a, b));
        }

        cout << (res != INF ? res : -1) << "\n";
    }

    return 0;
}