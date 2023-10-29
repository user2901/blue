#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), sorted(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }

    sort(sorted.begin(), sorted.end());
    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != sorted[i]) {
            l = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != sorted[i]) {
            r = i;
            break;
        }
    }

    for (int i = l, j = r; i < j;) {
        swap(a[i], a[j]);
        i++;
        j--;
    }

    if (a != sorted) {
        cout << "no";
        return 0;
    }

    cout << "yes\n" << l+1 << " " << r+1;
    return 0;
}