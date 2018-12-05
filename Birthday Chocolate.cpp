#include "stdc++.h"

int main() {
    int n, d, m;
    cin >> n;

    VI a(n);
    FOR(i, n) cin >> a[i];
    cin >> d >> m;

    int ans = 0;
    for (int sum=0, i=0; i<n; ++i) {
        sum += a[i];
        if (i-m>=0) sum -= a[i-m];
        if (i>=m-1) ans += sum == d;
    }

    cout << ans << endl;

    return 0;
}