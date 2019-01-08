#include "stdc++.h"

int main() {
    VI a(4);
    FOR(i, 4) cin >> a[i];
    sort(ALL(a));

    VVI f(a[2]+2, VI(4096));

    PER(c, a[2], 1) {
        f[c] = f[c+1];
        FOR(m, 4096)
            f[c][m] += ((c^m)<=a[3]) && ((c^m)>=c);
    }

    LL ans = 0;
    REP(x, 1, a[0])
        REP(y, x, a[1]) {
            int p = a[2] - y + 1;
            int q = a[3] - y + 1;
            ans += (2*q-p+1)*p/2 - f[y][x^y];
        }
 
    cout << ans << endl;


    return 0;
}