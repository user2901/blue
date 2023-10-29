#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int i = 0, j = n - 1;
    int res[2] = {0};
    int idx = 0;

    while (i <= j) {
        if (a[i] > a[j]) {
            res[idx] += a[i];
            i++;
        }
        else {
            res[idx] += a[j];
            j--;
        }
        idx = 1 - idx;
    }

    cout << res[0] << " " << res[1];
    return 0;
}