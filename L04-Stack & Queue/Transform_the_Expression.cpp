#include <iostream>
#include <stack>
using namespace std;

void transform(string expression) {
    stack<char> st;
    for (char c : expression) {
        if (isalpha(c)) cout << c;
        else if (c == ')') {
            cout << st.top();
            st.pop();
        }
        else if (c != '(') st.push(c);
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    string s;

    while (t--) {
        cin >> s;
        transform(s);
    }
    return 0;
}