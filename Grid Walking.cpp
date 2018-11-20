#include "stdc++.h"

int t, n, m;
int st[15], D[15];
LL ins[305][305];
const int M = 1e9 + 7;

void calcIns(int n, int m) {
    MEMSET(ins, 0);
    REP(i, 1, n) {
        ins[i][0] = 1;
        REP(j, 1, m)
            ins[i][j] = (ins[i-1][j] + ins[i][j-1]) % M;
    }
}

VLL dp(int d) {
    VVLL f(m+1, VLL(D[d]+1));
    VLL ans(m+1);

    f[0][st[d]] = ans[0] = 1;
    REP(i, 1, m) 
        REP(j, 1, D[d]) {
            if (j-1>0) f[i][j] = (f[i][j] + f[i-1][j-1]) % M;
            if (j+1<=D[d]) f[i][j] = (f[i][j] + f[i-1][j+1]) % M;
            ans[i] = (ans[i]+f[i][j]) % M;
        }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    calcIns(301, 300);

    while (t--) {
        cin >> n >> m;
        REP(i, 1, n) cin >> st[i];
        REP(i, 1, n) cin >> D[i];
        VLL f = dp(1);
        REP(i, 2, n) {
            auto g = dp(i);
            VLL nxt(m+1);
            nxt[0] = 1;
            REP(t, 1, m) 
                REP(pre, 0, t)
                    nxt[t] = (nxt[t] + f[pre]*g[t-pre]% M * ins[pre+1][t-pre]%M) % M;
            f = nxt;
        }
        cout << f[m] << endl;
    }

    return 0;
}