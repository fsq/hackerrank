#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(k);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++a[x % k];
    }
    int ans = a[0] > 0;
    for (int i=1, j=k-1; i<=j; ++i, --j)
        if (i==j)
            ans += a[i] > 0;
        else 
            ans += max(a[i], a[j]);
    cout << ans << endl;
    return 0;
}