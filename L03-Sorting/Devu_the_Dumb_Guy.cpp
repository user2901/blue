#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long selfLearning(vector<int> &subjects, int x) {
    sort(subjects.begin(), subjects.end());
    long long min_time = 0;
    for (int subject : subjects) {
        min_time += 1LL*subject*x;
        if (x > 1) x--;
    }
    return min_time;
}

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << selfLearning(a, x);
    return 0;
}