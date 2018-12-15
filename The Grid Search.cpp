#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);

    int t, n, m, r, c;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<string> a(n);
        FOR(i, n) cin >> a[i];

        cin >> r >> c;
        vector<string> b(r);
        FOR(i, r) cin >> b[i];

        bool found = false;
        REP(i, r-1, n-1) REP(j, c-1, m-1) {
            REP(p, i-r+1, i)
                if (b[r-(i-p+1)]!=a[p].substr(j-c+1, c))
                    goto nxt;
            found = true;
            goto out;
            nxt:;
        }

        out:
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}