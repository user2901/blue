#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int t = 0;
    
    for (int i = 0; i < n; i++) {
        if (t+15 < a[i]) {
            ans = t + 15;
            break;
        }
        else {
            t = a[i];
            ans = t + 15;
        }
    }

    cout << min(ans, 90);
    return 0;
}