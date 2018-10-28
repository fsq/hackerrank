#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        VI a(n+1);

        int ans1=0, ans2=INT_MIN, cur=0, nx=INT_MIN;

        REP(i, 1, n) {
            cin >> a[i];
            nx = max(nx, a[i]);
            if (a[i]>0) 
                ans1 += a[i];
            cur = max(cur+a[i], a[i]);
            ans2 = max(ans2, cur);
        }

        if (ans1==0) ans1 = nx;
        cout << ans2 << ' ' << ans1 << '\n';

    }
    return 0;
}