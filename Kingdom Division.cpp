#include "stdc++.h"

int n;
const LL M = 1e9 + 7;
VI e[100007];
int vis[100007];
LL f[100007][3][3];

LL dp(int x, int c, int fa) {
    if (f[x][c][fa]>=0) return f[x][c][fa];
    if (e[x].size()==1 && vis[e[x][0]])
        return c==fa;

    vis[x] = true;

    LL& ans = f[x][c][fa];
    ans = 1;
    for (auto y : e[x])
        if (!vis[y]) {
            ans *= (dp(y, 0, c) + dp(y, 1, c)) % M;
            ans %= M;
        }

    if (c != fa) { 
        LL inv = 1;
        for (auto y : e[x])
            if (!vis[y]) 
                inv = inv*dp(y, 1^c, c) % M;
        ans = (ans - inv + M) % M;
    }

    vis[x] = false;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(vis, 0, sizeof(vis));
    memset(f, 0x80, sizeof(f));

    for (int u,v,i=0; i+1<n; ++i) {
        cin >> u >> v;
        e[u].PB(v);
        e[v].PB(u);
    }

    cout << 2*dp(1, 0, 2) % M << endl;


    return 0;
}