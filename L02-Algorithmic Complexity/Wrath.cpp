#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    int j = n - 1; // biến j có ý nghĩa là vị trí cuối cùng của người bị giết trước đó
    int lastKill_pos = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        j = min(j, i);
        lastKill_pos = max(0, i - a[i]);
        if (j > lastKill_pos) {
            cnt += (j - lastKill_pos);
            j = lastKill_pos;
        }
    }

    cout << n - cnt;
    return 0;
}