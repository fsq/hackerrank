#include "stdc++.h"

LL a[50007];

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    a[0] = INT_MAX;
    while (t--) {
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        LL cur = 0, ans = 0;
        for (int j, i=n; i>0; i=j) {
            j = i-1;
            cur = 0;
            while (a[j]<a[i]) 
                cur += a[j--];
            // cout << i << ' ' << j << endl;
            ans += (i-j-1)*a[i] - cur;
        }
        cout << ans << endl;
    }
    return 0;
}