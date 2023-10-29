#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    queue<int> q;
    vector<int> discarded_cards;

    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) q.push(i);

        int x;
        while (q.size() >= 2) {
            x = q.front();
            q.pop();
            discarded_cards.push_back(x);
            x = q.front();
            q.pop();
            q.push(x);
        }

        cout << "Discarded cards:";
        for (int i = 0; i < n - 1; i++) {
            if (i != 0) cout << ",";
            cout << " " << discarded_cards[i];
        }
        
        cout << "\nRemaining card: " << q.front() << "\n";
        q.pop();
        discarded_cards.clear();
    }
    return 0;
}