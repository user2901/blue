#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, type, x;
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    bool isStack, isQueue, isPQ;

    while (cin >> n) {
        while (!st.empty()) st.pop();
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        isStack = isQueue = isPQ = true;

        for (int i = 0; i < n; i++) {
            cin >> type >> x;
            if (type == 1) {
                st.push(x);
                q.push(x);
                pq.push(x);
            }
            else {
                if (st.top() != x) isStack = false;
                if (q.front() != x) isQueue = false;
                if (pq.top() != x) isPQ = false;
                st.pop();
                q.pop();
                pq.pop();
            }
        }

        if (isStack + isQueue + isPQ == 0) cout << "impossible\n";
        else if (isStack + isQueue + isPQ > 1) cout << "not sure\n";
        else if (isStack) cout << "stack\n";
        else if (isQueue) cout << "queue\n";
        else cout << "priority queue\n";
    }

    return 0;
}