#include "stdc++.h"

int main() {
    VLL a(5);
    FOR(i, 5) cin >> a[i];
    LL sum = accumulate(ALL(a), 0ll);
    cout << sum-*max_element(ALL(a)) << ' ' << sum-*min_element(ALL(a)) << endl;
    return 0;
}