#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VLL a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a), greater<LL>());
    LL ans = 0;

    FOR(i, n) 
        ans += (1ll<<i) * a[i];
    cout << ans << endl;
    return 0;
}