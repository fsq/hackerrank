#include "stdc++.h"

VI count(const string& s) {
    VI cnt(26);
    FOREACH(c, s) ++cnt[c-'a'];
    return cnt;
}

int main() {
    int q;
    cin >> q;
    string s, t;
    while (q--) {
        cin >> s >> t;
        VI a = count(s), b = count(t);
        bool found = false;
        FOR(i, 26) 
            if (a[i] && b[i]) {
                found = true;
                break;
            }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}