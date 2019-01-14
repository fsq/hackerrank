#include "stdc++.h"

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    VI a(n);
    FOR(i, n) cin >> a[i];
    k %= n;

    int p;
    while (q--) {
        cin >> p;
        cout << a[(p-k+n) % n] << endl;
    }
    return 0;
}