#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;

    VI a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a));

    int ans = a.back() - a.front();
    for (int i=0; i+k-1<n; ++i)
        ans = min(ans, a[i+k-1] - a[i]);
    cout << ans << endl;

    return 0;
}