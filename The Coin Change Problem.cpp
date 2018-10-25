#include "stdc++.h"

int main() {
    int n, m;
    cin >> n >> m;
    VI a(m+1);
    REP(i, 1, m) cin >> a[i];

    vector<VLL> f(m+1, VLL(n+1));
    f[0][0] = 1;
    REP(i, 1, m) {
        f[i][0] = 1;
        REP(j, 1, n)
            f[i][j] = f[i-1][j] + (j>=a[i] ? f[i][j-a[i]] : 0);
    }

    cout << f[m][n] << endl;
    return 0;
}