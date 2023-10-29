#include <iostream>
#include <vector>
using namespace std;

bool checkJacket(vector<int> v, int n) {
    if (n == 1) {
        if (v[0] == 1) return true;
        else return false;
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) cnt++;
    }
    return cnt == 1;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << (checkJacket(v, n) ? "YES" : "NO");
    return 0;
}