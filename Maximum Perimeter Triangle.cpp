#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VLL a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a), greater<int>());

    FOR(i, n-2)
        if (a[i] < a[i+1]+a[i+2]) {
            cout << a[i+2] << ' ' << a[i+1] << ' ' << a[i] << endl;
            return 0;
        }
    cout << -1 << endl;
    return 0;
}