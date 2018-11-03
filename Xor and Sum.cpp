#include "stdc++.h"

string s1, s2;
const int L = 314160;
const int M = 1e9 + 7;

int a[500000], b[500000], p[500000];

int main() {
    ios::sync_with_stdio(false);
    MEMSET(a, 0);
    MEMSET(b, 0);
    cin >> s1 >> s2;

    FOR(i, s1.size()) a[s1.size()-i-1] = s1[i]-'0';
    FOR(i, s2.size()) b[s2.size()-i-1] = s2[i]-'0';

    p[0] = 1;
    int n = max(s1.size(), s2.size());
    REP(i, 1, n+L)
        p[i] = (p[i-1]<<1) % M;

    LL ans = 0;
    int ones = 0;
    PER(i, n+L-1, n) ones += b[i];

    PER(i, n+L-1, 0) {
        if (a[i])
            ans += (LL)p[i] * (L-ones);
        else
            ans += (LL)p[i] * ones;
        ans %= M;
        if (b[i]) --ones;
        if (i-L>=0 && b[i-L]) ++ones;
    }

    cout << ans << endl;

    return 0;
}