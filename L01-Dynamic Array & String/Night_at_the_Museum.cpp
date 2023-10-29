#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    char start = 'a';
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - start;
        int y = start - s[i];

        if (x < 0) x += 26;
        if (y < 0) y += 26;
        
        ans += min(x, y);
        start = s[i];
    }

    cout << ans;
    return 0;
}