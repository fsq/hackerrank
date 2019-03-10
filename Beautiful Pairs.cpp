#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(1001), b=a;

    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++a[x];
    }
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++b[x];
    }

    int ans = 0;
    REP(i, 1, 1000) ans += min(a[i], b[i]);
    cout << (ans==n ? n-1 : ans+1) << endl;
    return 0;
}