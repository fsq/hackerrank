#include "stdc++.h"

int main() {
    int n, m;
    cin >> n >> m;

    VI a(n), b(m);
    FOR(i, n) cin >> a[i];
    FOR(i, m) cin >> b[i];

    int lo=*max_element(ALL(a)), hi=*min_element(ALL(b));

    int ans = 0 ;
    REP(x, lo, hi) 
        if (all_of(ALL(a), [=](int y) {
            return x % y==0;
        }) && all_of(ALL(b), [=](int y) {
            return y % x==0;
        }))
            ++ans;
    cout << ans << endl;

    return 0;
}