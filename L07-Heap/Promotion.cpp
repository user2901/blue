#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;

struct Bill
{
    int id, price;
};

struct BillASCPrice
{
    bool operator() (const Bill &a, const Bill &b) {
        return a.price < b.price; // max heap
    }
};

struct BillDSCPrice
{
    bool operator() (const Bill &a, const Bill &b) {
        return a.price > b.price; // min heap
    }
};

/*
    - minHeap: top là phiếu có GTNN
    - maxHeap: top là phiếu có GTLN
    - sau khi lấy 2 phiếu top của minHeap và maxHeap ra, ta pop cả 2 heap
    - tuy nhiên nếu chỉ làm vậy thì phiếu bị pop ở maxHeap có thể còn trong minHeap và ngược lại
    ->  dùng taken[id] để đánh dấu những phiếu đã bị pop ra, ở những lần sau khi gặp những phiếu này ở maxHaeap thì ta pop hết. Làm tương tự với minHeap
*/

int main() {
    int n, k, x, idx = 0;
    cin >> n;

    priority_queue<Bill, vector<Bill>, BillASCPrice> maxHeap;
    priority_queue<Bill, vector<Bill>, BillDSCPrice> minHeap;
    bool taken[MAX] = {};
    long long ans = 0;

    while (n--) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> x;
            idx++;
            minHeap.push(Bill{idx, x});
            maxHeap.push(Bill{idx, x});
        }

        while (taken[maxHeap.top().id]) {
            maxHeap.pop();
        }

        while (taken[minHeap.top().id]) {
            minHeap.pop();
        }

        ans += maxHeap.top().price - minHeap.top().price;
        taken[minHeap.top().id] = taken[maxHeap.top().id] = true;
        minHeap.pop();
        maxHeap.pop();
    }

    cout << ans;
    return 0;
}