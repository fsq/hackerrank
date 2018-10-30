#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    VLL a(n+1);
    REP(i, 1, n) cin >> a[i];
    sort(ALL(a));

    VVLL f(n+1, VLL(k+1, LLONG_MAX));
    f[0][0] = 0;

    REP(i, 1, n) {
        f[i][0] = f[i-1][0] - k*a[i];
        REP(j, 1, min(k, i)) {
            if (i-1>=j) f[i][j] = f[i-1][j]+(2*j-k)*a[i];
            f[i][j] = min(f[i][j], f[i-1][j-1]+(2*i-2*j-n+k)*a[i]);
        }
    }

    cout << f[n][k] << endl;

    return 0;
}