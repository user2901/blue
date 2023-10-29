#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 5;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int Min = INF, Max = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] < Min) Min = a[i];
        if (b[i] > Max) Max = b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == Min && b[i] == Max) {
            cout << i+1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}