#include "stdc++.h"

int n, k;
const int N = 75;
VVLL g(N, VLL(N));
VVI e(N);

void dp(int x, int fa) {
    VI sons;
    FOREACH(y, e[x])
        if (y != fa) {
            sons.PB(y);
            dp(y, x);
        }

    int n = sons.size();
    VVLL f(n+1, VLL(k+1));
    f[0][0] = 1;
    REP(i, 1, n)
        REP(j, 0, k) {
            if (j>0) f[i][j] = f[i-1][j-1];
            REP(p, 0, j)
                f[i][j] += f[i-1][j-p] * g[sons[i-1]][p];
        }
    copy(f.back().begin(), f.back().end(), g[x].begin());
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    
    for (int u,v,i=0; i+1<n; ++i) {
        cin >> u >> v;
        e[u].PB(v);
        e[v].PB(u);
    }

    int root = rand()%n + 1;
    dp(root, 0);

    LL ans = 0;
    REP(i, 1, n) 
        for (int j=0; j+(i!=root)<=k; ++j)
            ans += g[i][j];

    cout << ans+1 << endl;

    return 0;
}