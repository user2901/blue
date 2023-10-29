#include <iostream>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int sCount[26] = {0}, tCount[26] = {0};
    bool need_tree = false, automaton = false, array = false;

    for (int i = 0; i < s.size(); i++) sCount[s[i] - 'a']++;
    for (int i = 0; i < t.size(); i++) tCount[t[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (sCount[i] < tCount[i]) need_tree = true;
        else if (sCount[i] > tCount[i]) automaton = true;
    }

    int idx_found = 0, match = -1;
    for (int i = 0; i < t.size(); i++) {
        idx_found = s.find_first_of(t[i], match+1);

        if (idx_found > match) match = idx_found;
        else {
            array = true;
            break;
        }
    }

    // thu tu uu tien: need tree -> both -> automaton -> array
    if (need_tree) cout << "need tree";
    else if (automaton && array) cout << "both";
    else if (automaton) cout << "automaton";
    else cout << "array";

    return 0;
}