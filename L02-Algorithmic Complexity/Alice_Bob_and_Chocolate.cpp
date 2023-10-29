#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int t_alice = 0, t_bob = 0;
    int i = 0, j = n - 1;

    while (i <= j) {
        if (t_alice + a[i] <= t_bob + a[j]) {
            t_alice += a[i];
            i++;
        }
        else {
            t_bob += a[j];
            j--;
        }
    }

    cout << i << " " << n - i;
    return 0;
}