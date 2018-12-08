#include "stdc++.h"

int main() {
    int n, m, budget;
    cin >> budget >> n >> m;
    VI a(n), b(m);
    FOR(i, n) cin >> a[i];
    FOR(i, m) cin >> b[i];
    sort(ALL(a)), sort(ALL(b));

    if (a[0]+b[0] > budget) 
        cout << -1 << endl;
    else {
        int mx = 0;
        for (int i=0, j=m-1; i<n && j>=0; )
            if (a[i]+b[j] > budget)
                --j;
            else {
                mx = max(mx, a[i] + b[j]);
                if (mx==budget) break;
                ++i;
            }
        cout << mx << endl;
    }
    return 0;
}