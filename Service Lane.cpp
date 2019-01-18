#include "stdc++.h"

int main() {
    int n, t;
    cin >> n >> t;
    VI a(n+1);
    VVI cnt;
    cnt.PB({0, 0, 0});
    REP(i, 1, n) {
        cin >> a[i];
        cnt.PB(cnt.back());
        ++cnt.back()[a[i]-1];
    }
    int l, r;
    while (t--) {
        cin >> l >> r;
        VI seg(3);
        FOR(i, 3) {
            seg[i] = cnt[r][i] - cnt[l-1][i];
            if (seg[i]) {
                cout << i+1 << endl;
                break;
            }
        }
    }


    return 0;
}