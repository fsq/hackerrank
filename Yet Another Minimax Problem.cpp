#include "stdc++.h"

int high_bit(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x ^= x >> 1;
    return x;
}

int main() {
    int n;
    cin >> n;
    VI a(n);
    FOR(i, n) cin >> a[i];
    sort(ALL(a), greater<int>());

    while (a.front()>0 && high_bit(a.front())==high_bit(a.back())) {
        auto b = high_bit(a.front());
        for (auto& x : a) x-=b;
    }
    
    int it = upper_bound(ALL(a), high_bit(a.front()), greater<int>()) - a.begin();

    int ans = INT_MAX;
    REP(i, 0, it-1) REP(j, it, n-1)
        ans = min(ans, a[i] ^ a[j]);
    cout << (ans==INT_MAX ? 0 : ans) << endl;

    return 0;
}