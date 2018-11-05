#include "stdc++.h"

int n;
const int N = 1e6 + 7;
LL a[N], g[N], d[N], p[N], f[N];
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, 1, n) cin >> a[i];

    g[0] = 1;
    d[0] = p[0] = 0;

    REP(i, 1, n) {
        int l = a[i];
        f[i] = 16*l*g[i-1]%M*g[i-1]%M + 12*g[i-1]%M*d[i-1]%M + + 8*d[i-1] + 12*g[i-1]*l%M + l + 4*f[i-1];
        f[i] %= M;

        g[i] = (g[i-1]*4+2) % M;
        p[i] = (p[i-1]*2+3*l) % M;
        d[i] = (4*d[i-1] + 8*g[i-1]*l + 3*g[i-1]*p[i-1]%M + 3*l + 2*p[i-1]) % M;
    }

    cout << f[n] << endl;

    return 0;
}