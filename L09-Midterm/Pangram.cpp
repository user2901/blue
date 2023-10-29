#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) s[i] = tolower(s[i]);

    bool vis[26] = {};
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[s[i]-'a']) {
            vis[s[i]-'a'] = true;
            cnt++;
        }
    }
    
    cout << (cnt == 26 ? "YES" : "NO");
    return 0;
}