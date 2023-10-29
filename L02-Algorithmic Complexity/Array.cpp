#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int freq[MAX] = {0};
    int unique = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 0) {
            unique++;
        }
        freq[a[i]]++;

        while (unique == k) {
            freq[a[j]]--;
            if (freq[a[j]] == 0) {
                cout << j + 1 << " " << i + 1;
                return 0;
            }        
            j++;
        }
    }

    cout << "-1 -1";
    return 0;
}