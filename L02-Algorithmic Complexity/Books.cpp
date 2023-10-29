#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int start = 0, read_time = 0, max_book = 0;
    for (int i = 0; i < n; i++) {
        read_time += a[i];
        while (read_time >= t) {
            read_time -= a[start];
            start++;
        }

        max_book = max(max_book, i-start+1);
    }

    cout << max_book;
    return 0;
}