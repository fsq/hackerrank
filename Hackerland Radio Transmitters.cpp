#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a));

    int ans = 0;
    for (int j,i=0; i<n; ) {
        for (j=i; j<n && a[j]<=a[i]+k; ++j);
        ++ans;
        for (i=j; i<n && a[i]<=a[j-1]+k; ++i);
    }

    cout << ans << endl;
    return 0;
}