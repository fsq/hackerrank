#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a));

    int cnt = 0;
    for (int i=0; i<n && k>=a[i]; ++i) {
        k -= a[i];
        ++cnt;
    }

    cout << cnt << endl;
    return 0;
}