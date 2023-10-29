#include <iostream>
#include <stack>
using namespace std;
const int MAX = 1005;

int main() {
    int n;
    int a[MAX];
    stack<int> st;

    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> a[i];

        int ordering = 1;
        int i = 0;
        
        while (i < n) {
            if (a[i] == ordering) {
                i++;
                ordering++;
            }
            else if (!st.empty() && st.top() == ordering) {
                ordering++;
                st.pop();
            }
            else {
                st.push(a[i]);
                i++;
            }
        }

        while (!st.empty() && st.top() == ordering) {
            ordering++;
            st.pop();
        }

        cout << (ordering == n+1 ? "yes\n" : "no\n");
        while (!st.empty()) {
            st.pop();
        }
    }
    return 0;
}