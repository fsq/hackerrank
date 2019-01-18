#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(n+1);
    REP(i, 1, n) cin >> a[i];

    int ans = 0, pg = 1;
    REP(i, 1, n) {
        REP(j, 1, a[i]) {
            int now = pg + (j-1)/k;
            if (now==j) ++ans;
        }
        pg += a[i]/k + (a[i]%k!=0);
    }
    cout << ans << endl;

    return 0;
}