#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);

    int t, n;
    VI a;

    cin >> t;
    while (t--) {
        cin >> n;
        a = VI(n);

        FORI(i, a) cin >> a[i];
        int mn = *min_element(ALL(a));
        int ans = INT_MAX;

        REP(base, mn-5, mn) {
            int cnt = 0;
            FOREACH(x, a) {
                int d = x - base;
                cnt += d / 5;
                d %= 5;
                cnt += d / 2;
                d %= 2;
                cnt += d;
            }
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
        
    }

    return 0;
}