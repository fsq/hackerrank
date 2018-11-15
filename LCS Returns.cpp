#include "stdc++.h"

string a, b;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    n = a.size(), m = b.size();
    a.insert(a.begin(), ' ');
    b.insert(b.begin(), ' ');

    VVI f(n+4, VI(m+4));
    VVI g(n+4, VI(m+4));
    REP(i, 1, n)
        REP(j, 1, m)
            f[i][j] = a[i]==b[j] ? f[i-1][j-1]+1 : 
                                    max(f[i-1][j], f[i][j-1]);

    PER(i, n, 1)
        PER(j, m, 1)
            g[i][j] = a[i]==b[j] ? g[i+1][j+1]+1 :
                                    max(g[i+1][j], g[i][j+1]);

    int ori = f[n][m];
    int ans = 0;
    REP(i, 0, n) {
        VI vis(128);
        REP(j, 0, m-1) {
            int now = f[i][j] + 1 + g[i+1][j+2];
            if (now==ori+1 && ++vis[b[j+1]]==1)  
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}