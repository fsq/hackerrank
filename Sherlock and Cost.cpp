#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        VI a(n);
        FORI(i, a) cin >> a[i];

        VVI f(n, VI(2));
        REP(i, 1, n-1) {
            f[i][0] = max(f[i-1][0], f[i-1][1]+a[i-1]-1);
            f[i][1] = max(f[i-1][0]+a[i]-1, f[i-1][1]+abs(a[i]-a[i-1]));
        }

        cout << max(f[n-1][0], f[n-1][1]) << '\n';
    }

    return 0;
}