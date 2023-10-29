#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, type, nreviews = 0;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> top3; // min heap dùng để lưu top (n/3) thằng đầu
    priority_queue<int> rest; // max heap lưu phần còn lại

    while (n--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            nreviews++;

            // nếu x > thằng nhỏ nhất trong top3 và top3 ko empty -> push top của top3 vào rest và push x vào top3
            if (!top3.empty() && x > top3.top()) {
                int temp = top3.top();
                top3.pop();
                rest.push(temp);
                top3.push(x);
            }
            // ngược lại thì push vào rest
            else rest.push(x);

            // nếu nreviews chia hết cho 3 -> đưa 1 thằng top từ rest sang top3
            if (nreviews % 3 == 0) {
                int temp = rest.top();
                rest.pop();
                top3.push(temp);
            }
        }
        else {
            if (top3.empty()) cout << "No reviews yet\n";
            else cout << top3.top() << "\n";
        }
    }

    return 0;
}