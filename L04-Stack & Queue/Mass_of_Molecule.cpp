#include <iostream>
#include <stack>
using namespace std;

int mass(char c) {
    return c == 'H' ? 1 : c == 'C' ? 12 : 16;
}

int main() {
    string s; cin >> s;
    int x, mol;
    stack<int> st;

    for (char c : s) {
        if (isalpha(c)) {
            st.push(mass(c));
        }
        else if (isdigit(c)) {
            mol = st.top()*(c - '0');
            st.pop();
            st.push(mol);
        }
        else if (c == '(') {
            st.push(-1);
        }
        else if (c == ')') {
            x = 0;
            while (st.top() != -1) {
                x += st.top();
                st.pop();
            }

            st.pop();
            st.push(x);
        }
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans;
    return 0;
}