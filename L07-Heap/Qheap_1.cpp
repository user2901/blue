#include <iostream>
#include <queue>
using namespace std;

int main() {
    int Q, v, x;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> pq, pqRemove;

    while (Q--) {
        cin >> x;
        if (x == 1) {
            cin >> v;
            pq.push(v);
        }
        else if (x == 2) {
            cin >> v;
            pqRemove.push(v);
        }
        else {
            while (!pqRemove.empty() && pq.top() == pqRemove.top()) {
                pq.pop();
                pqRemove.pop();
            }
            cout << pq.top() << "\n";
        }
    }
    
    return 0;
}