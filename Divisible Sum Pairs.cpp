#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(k);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++a[x % k];
    }

    int ans = a[0]*(a[0]-1) / 2;
    for (int i=1; k-i>=i; ++i) 
        if (k-i==i) 
            ans += a[i]*(a[i]-1) / 2;
        else 
            ans += a[i] * a[k-i];
    cout << ans << endl;
    return 0;
}