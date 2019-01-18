#include "stdc++.h"

int main() {
    int n, m, ans=0;
    cin >> n >> m;
    VI a(m);
    FOR(i, m) cin >> a[i];
    sort(ALL(a));

    int pre=-1, x;
    FOR(i, m) {
        if (i==0)
            ans = max(ans, a[i]-1);
        else 
            ans = max(ans, (a[i]-a[i-1])/2-1+2*((a[i]-a[i-1])%2));
    }
    ans = max(ans, (n-1-a.back())/2-1+2*((n-1-a.back()%2)));
    cout << ans << endl;
    return 0;
}