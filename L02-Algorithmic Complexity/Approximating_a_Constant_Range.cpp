#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int freq[MAX] = {0};
    int unique = 0, j = 0, longest_range = 0;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 0) {
            unique++;
        }
        freq[a[i]]++;

        while (j < n && unique > 2) {
            if (freq[a[j]] == 1) {
                unique--;
            }
            freq[a[j]]--;
            j++;
        }

        longest_range = max(longest_range, i-j+1);
    }

    cout << longest_range;
    return 0;
}