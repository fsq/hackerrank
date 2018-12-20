#include "stdc++.h"

int main() {
    int n, m;
    cin >> n;
    VI a(n);
    FOR(i, n) cin >> a[i];
    n = unique(ALL(a)) - a.begin();
    a.insert(a.begin(), INT_MAX);

    cin >> m;
    for (int p=n, x, i=0; i<m; ++i) {
        cin >> x;
        while (a[p]<=x) --p;
        cout << p + 1 <<'\n';
    }


    return 0;
}