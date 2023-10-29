#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    string pass; cin >> pass;
    int len = pass.size();
    int small_len = 0, same_len = 0;

    for (int i = 0; i < n; i++) {
        if (s[i].size() < len) small_len++;
        else if (s[i].size() == len) same_len++; // chu y truong hop s[i].size() > len
    }

    int best_time = small_len + 5*(small_len/k) + 1;
    int worst_time = small_len + same_len - 1 + 5*((small_len + same_len - 1)/k) + 1;
    cout << best_time << " " << worst_time;
    return 0;
}