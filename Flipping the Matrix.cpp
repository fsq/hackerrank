#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        VVI a(2*n, VI(2*n));
        FOR(i, 2*n) FOR(j, 2*n) cin >> a[i][j];
        int ans = 0;
        FOR(i, n) FOR(j, n) 
            ans += max(max(a[i][j], a[i][2*n-1-j]),
                       max(a[2*n-1-i][j], a[2*n-1-i][2*n-1-j]));
        cout << ans << endl;

    }
    return 0;
}