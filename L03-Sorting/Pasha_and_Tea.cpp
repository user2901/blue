#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, w; cin >> n >> w;
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    double ans = 3 * min(1.0*a[0], 1.0*a[n]/2) * n;
    ans = min(ans, 1.0*w);
    cout << fixed << setprecision(6) << ans;
    return 0;
}