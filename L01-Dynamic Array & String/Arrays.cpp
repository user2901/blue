#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nA, nB, k, m;
    cin >> nA >> nB >> k >> m;
    vector<int> a(nA), b(nB);
    for (int i = 0; i < nA; i++) cin >> a[i];
    for (int i = 0; i < nB; i++) cin >> b[i];
    
    cout << (a[k-1] < b[nB-m] ? "YES" : "NO");
    return 0;
}