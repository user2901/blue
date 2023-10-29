#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> l(n), h(1001);

    int nTowers = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        if (h[l[i]] == 0) nTowers++;
        h[l[i]]++;
    }

    sort(h.begin(), h.end(), greater<int>());
    cout << h[0] << " " << nTowers;
    return 0;
}