#include "stdc++.h"

const LL M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n, r, s;

    cin >> n >> r >> s;

    if (((r+s) & 1) || r<s) {
        cout << 0 << endl;
        return 0;
    }

    VI a(n+1);
    REP(i, 1, n) 
        cin >> a[i];
    
    int sum = (r + s)/2;
    VVI f(n+1, VI(sum+1));
    f[0][0] = 1;
    REP(i, 1, n) 
        PER(l, i, 1) PER(s, sum, a[i])
            f[l][s] = (f[l][s]+f[l-1][s-a[i]]) % M;
    
    LL ans = 0;
    REP(l, 1, n)
        ans = (ans + (LL)f[l][(r+s)>>1]*f[l][(r-s)>>1]%M) % M;

    cout <<  ans << endl;

    return 0;
}