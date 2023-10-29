#include <iostream>
#include <queue>
using namespace std;

struct Job
{
    int pos, priority;
};


int main() {
    int T; cin >> T;
    int n, m, x;
    queue<Job> q;
    priority_queue<int> pq;

    while (T--) {
        cin >> n >> m;
        int res = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;
            q.push(Job{i, x});
            pq.push(x);
        }

        while (!pq.empty()) {
            if (pq.top() == q.front().priority) {
                res++;

                if (q.front().pos == m) {
                    break;
                }

                q.pop();
                pq.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }

        cout << res << "\n";

        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
    }

    return 0;
}