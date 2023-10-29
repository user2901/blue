#include <iostream>
#include <vector>
using namespace std;

struct Vest
{
    int u, v;
};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<Vest> v;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (a[i] - x <= b[j] && a[i] + y >= b[j]) {
            v.push_back((Vest){i+1, j+1});
            i++;
            j++;
        }
        else if (b[j] > a[i] + y) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << v.size() << "\n";
    for (Vest &vest : v)
        cout << vest.u << " " << vest.v << "\n";
    return 0;
}