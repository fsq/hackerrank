#include "stdc++.h"

int main() {
    int n;
    cin >> n;


    VI a(n);
    FOR(i, n) cin >> a[i];

    VI lf(n, 1), rt(n, 1);
    REP(i, 1, n-1)
        if (a[i]>a[i-1])
            lf[i] = lf[i-1] + 1;

    PER(i, n-2, 0)
        if (a[i]>a[i+1])
            rt[i] = rt[i+1]+ 1;

    LL ans = 0;
    FOR(i, n)
        ans += max(lf[i], rt[i]);

    cout << ans << endl;

    return 0;
}