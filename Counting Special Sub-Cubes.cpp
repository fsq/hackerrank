#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<VVI> pre(n, VVI(n, VI(n))), f = pre;
        VI ans(n+1);
        FOR(i, n) FOR(j, n) FOR(k, n) {
            cin >> pre[i][j][k];
            ans[1] += pre[i][j][k]==1;
        }
        cout << ans[1] <<' ';

        REP(l, 2, n) {
            FOR(i, n-l+1) FOR(j, n-l+1) FOR(k, n-l+1) {
                f[i][j][k] = 0;
                FOR(dx, 2) FOR(dy, 2) FOR(dz, 2) 
                    f[i][j][k] = max(f[i][j][k], pre[i+dx][j+dy][k+dz]);
                ans[l] += f[i][j][k]==l;
            }
            cout << ans[l] << ' ';
            pre.swap(f);
        }
        cout << '\n';
    }
    return 0;
}