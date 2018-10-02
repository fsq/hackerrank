#include "stdc++.h"

const int M = 1e9;
int n, m;
VVI e, et;
VI fa, f, vis, g;

void dfs(int u, VVI& e, vector<int>& a) {
    vis[u] = true;
    FOREACH(v, e[u])
        if (!vis[v])
            dfs(v, e, a);
    a.PB(u);
}

int dp(int u) {
    if (u==n) return 1;
    if (vis[u]) return f[u];
    vis[u] = true;
    FOREACH(v, e[u]) {
        int nxt = dp(fa[v]);
        if (nxt==-1) return f[u]=-1;
        f[u] = (f[u]+nxt) % M;
        if (f[u] && g[u]) return f[u] = -1;
    }
    return f[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    e.resize(n+1), et.resize(n+1);
    for (int u,v,i=0; i<m; ++i) {
        cin >> u >> v;
        e[u].PB(v);
        et[v].PB(u);
    }

    fa.resize(n+1); iota(ALL(fa), 0);
    f.resize(n+1);
    vis.resize(n+1);
    g.resize(n+1);

    VI ord;
    REP(i, 1, n)
        if (!vis[i]) 
            dfs(i, e, ord);
    FILL(vis, 0);
    PER(i, n-1, 0) {
        int u = ord[i];
        if (!vis[u]) {
            VI group;
            dfs(u, et, group);
            if (group.size()>1) 
                FOREACH(v, group) {
                    g[v] = true;
                    fa[v] = u;
                    if (v!=u)
                        FOREACH(y, e[v])
                            e[u].PB(y);
                }
        }
    }

    FILL(vis, 0);
    int ans = g[1] || g[n] ? -1 : dp(1);

    cout << (ans==-1 ? "INFINITE PATHS" : to_string(ans)) << endl;
    return 0;
}