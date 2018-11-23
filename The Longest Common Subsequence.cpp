#include "stdc++.h"

int main() {
    int n, m;
    cin >> n >> m;
    VI a(n+1), b(m+1);
    REP(i, 1, n) cin >> a[i];
    REP(i, 1, m) cin >> b[i];

    VVI f(n+1, VI(m+1)), g(n+1, VI(m+1));
    REP(i, 1, n) REP(j, 1, m)
        if (a[i]==b[j])
            f[i][j] = f[i-1][j-1] + 1;
        else if (f[i][j-1]>f[i-1][j]) {
            g[i][j] = 2;
            f[i][j] = f[i][j-1];
        } else {
            g[i][j] = 1;
            f[i][j] = f[i-1][j];
        }

    int i=n, j=m;
    VI ans;
    while (i>0 && j>0)
        if (a[i]==b[j]) {
            ans.PB(a[i]);
            --i, --j;
        } else if (g[i][j]==1)
            --i;
        else
            --j;
    ROFI(i, ans) cout << ans[i] << ' '; 
    cout << endl;
    return 0;
}