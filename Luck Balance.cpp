#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;

    VI a;
    int ans = 0;
    for (int x,t,i=0; i<n; ++i) {
        cin >> x >> t;
        if (t == 1)
            a.PB(x);
        else 
            ans += x;
    }
    sort(ALL(a), greater<int>());
    ans += accumulate(a.begin(), min(a.begin()+k, a.end()), 0);
    ans -= accumulate(min(a.begin()+k, a.end()), a.end(), 0);
    cout << ans << endl;
    return 0;
}