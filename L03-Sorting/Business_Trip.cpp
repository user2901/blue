#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k; cin >> k;
    vector<int> a(12);
    for (int i = 0; i < 12; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    int ans = 0, height = 0;

    for (int i = 0; i < 12; i++) {
        if (height >= k) break;
        height += a[i];
        ans++;
    }

    cout << (height >= k ? ans : -1);
    return 0;
}