#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2005;

int main() {
    int n; cin >> n;
    vector<int> a(n+1), sorted(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }

    int ranked[MAX] = {0};
    sort(sorted.begin()+1, sorted.end(), greater<int>());

    for (int i = 1; i <= n; i++) {
        if (!ranked[sorted[i]]) ranked[sorted[i]] = i;
    }

    for (int i = 1; i <= n; i++) cout << ranked[a[i]] << " ";
    return 0;
}