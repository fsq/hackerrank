#include "stdc++.h"

VI a, vis, s;
VVI e;
int ans,tot;

int getSum(int u) {
    vis[u] = true;
    s[u] = a[u];
    FOREACH(v, e[u])
        if (!vis[v]) 
            s[u] += getSum(v);
    return s[u];
}

void dfs(int u) {
    vis[u] = true;
    ans = min(ans, abs(tot-2*s[u]));
    FOREACH(v, e[u])
        if (!vis[v])
            dfs(v);
}

int main() {
    int n;
    cin >> n;

    a = s = vis = VI(n+1);
    e.resize(n+1);
    REP(i, 1, n) cin >> a[i];
    for (int u,v,i=0; i+1<n; ++i) {
        cin >> u >> v;
        e[u].PB(v);
        e[v].PB(u);
    }

    ans = tot = getSum(1);
    FILL(vis, false);
    dfs(1);
    cout << ans << endl;
    return 0;
}