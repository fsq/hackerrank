#include "stdc++.h"

int main() {
    int n;
    cin >> n;

    VI cnt(101);
    int ans = 0, x;

    FOR(i, n) {
        cin >> x;
        ans = max(ans, ++cnt[x]);
    }
    cout << n-ans << endl;
    return 0;
}