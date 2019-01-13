#include "stdc++.h"

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        VI a(n);
        FOR(i, n) cin >> a[i];

        cout << (count_if(ALL(a), [](int x){ return x<=0; })>=k ? "YES" : "NO") << endl;
    }
    return 0;
}