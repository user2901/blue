#include <iostream>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;
    int x = k*w*(w+1)/2 - n;
    cout << (x > 0 ? x : 0);
    return 0;
}