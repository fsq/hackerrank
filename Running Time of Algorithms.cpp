#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(n);
    FOR(i, n) cin >> a[i];
    int ans = 0;
    REP(i, 1, n-1) 
        for (int j=i; j>0 && a[j]<a[j-1]; swap(a[j], a[j-1]), --j, ++ans);
    cout << ans << endl;
    return 0;
}