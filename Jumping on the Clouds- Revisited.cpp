#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(n);
    FOR(i, n) cin >> a[i];

    int x = 0, e = 100;
    do {
        x = (x+k) % n;
        --e;
        if (a[x]==1) e -= 2;
    } while (x!=0);
    cout << e << endl;
    return 0;
}