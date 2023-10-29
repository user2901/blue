#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);

        if (i < 2) cout << -1 << "\n";
        else {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int third = pq.top();
            pq.pop();

            cout << 1LL*first*second*third << "\n";

            pq.push(first);
            pq.push(second);
            pq.push(third);
        }
    }
    
    return 0;
}