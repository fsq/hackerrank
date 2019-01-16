#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(n+1);
    REP(i, 1, n) cin >> a[i];
    int ans = 0, i = 1;
    while (i<n) 
        if (i+2<=n && a[i+2]==0)
            ++ans, i += 2;
        else 
            ++ans, ++i;
    cout << ans << endl;
    return 0;
}