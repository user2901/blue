#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, b; cin >> n >> b;
    long long t, d, processing = 0;
    queue<long long> q;

    for (int i = 0; i < n; i++) {
        cin >> t >> d;
        while (!q.empty() && q.front() <= t) {
            q.pop();
        }

        // t < q.front() thì ko vào vòng while và tiếp tục đi xuống if-else phía dưới
        // nếu q.size() <= b thì push, ngược lại thì bỏ qua

        // vì sao <= b mà ko phải < b
        // đúng ra truy vấn đang được xử lý sẽ ko push vào queue, nhưng mình solve = cách push cả truy vấn này vào queue cho dễ xét q.front()
        if (q.size() <= b) {
            processing = max(processing, t) + d;
            cout << processing << " ";
            q.push(processing);
        }
        else cout << -1 << " ";
    }
    return 0;
}