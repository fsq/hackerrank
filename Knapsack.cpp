#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        VI a(n+1);
        REP(i, 1, n) cin >> a[i];
        VVI f(n+1, VI(k+1));
        f[0][0] = true;
        REP(i, 1, n) {
            f[i][0] = true;
            REP(j, 1, k)
                f[i][j] = f[i-1][j] || (j>=a[i] && f[i][j-a[i]]);
        }
        PER(j, k, 0)
            if (f[n][j]) {
                cout << j << '\n';
                break;
            }
    }
    return 0;
}