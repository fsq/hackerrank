#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        VI a(n+1);
        LL sum = 0;
        REP(i, 1, n) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin()+1, a.end());

        LL ans = sum, cur = 0;
        REP(i, 1, n) {
            cur += a[i];
            ans = max(ans, (i+1)*(sum-cur));
        }
        cout << ans << endl;
    }

    return 0;
}