#include "stdc++.h"

int main() {
    int n, m;
    cin >> n >> m;

    VI a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a), greater<int>());
    int ans = 0;
    FOR(i, n) 
        ans += (i/m+1) * a[i];
    cout << ans << endl;
    return 0;
}