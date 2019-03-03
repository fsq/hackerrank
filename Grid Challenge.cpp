#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> s(n);
        FOR(i, n) {
            cin >> s[i];
            sort(ALL(s[i]));
        }

        bool ok = true;
        FOR(i, n) 
            FOR(j, n-1) 
                if (s[j+1][i] < s[j][i]) {
                    ok = false;
                    goto out;
                }
        out:
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}