#include "stdc++.h"

int main() {
    int n, d, x;
    LL ans=0;
    VI a(20001);
    cin >> n >> d;
    FOR(i, n) {
        cin >> x;
        if (x>=2*d)
            ans += a[x-d] * a[x-2*d];
        ++a[x];
    }
    cout << ans << endl;
    return 0;
}