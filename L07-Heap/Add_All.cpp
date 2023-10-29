#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, x;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> x;
            pq.push(x);
        }

        long long ans = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a+b);
        }

        cout << ans << "\n";
        pq.pop();
    }

    return 0;
}