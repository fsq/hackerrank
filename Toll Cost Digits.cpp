#include "stdc++.h"

int n, m;
vector<vector<PII>> e;

VVI vis, cnt;
VI visn, rel;

void dfs(int rt) {
    queue<PII> q;
    q.push({rt, 0});
    vis[rt][0] = true;
    VI group, now(11);

    while (!q.empty()) {
        int u=q.front().first, d=q.front().second;
        q.pop();
        if (!visn[u]) {
            visn[u] = true;
            rel[u] = d;
            group.PB(u);
        }
        ++now[d];
        for (auto& p : e[u]) {
            int dt = (d+p.second) % 10, v = p.first;
            if (!vis[v][dt]) {
                vis[v][dt] = true;
                q.push({v, dt});
            }
        }
    }

    for (auto x : group)
        FOR(k, 10)
            cnt[x][k] = now[(k+rel[x]) % 10] - vis[x][(k+rel[x]) % 10];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    e.resize(n+1);
    visn = rel = VI(n+1);
    vis = cnt = VVI(n+1, VI(11));

    for (int u,v,r,i=0; i<m; ++i) {
        cin >> u >> v >> r;
        e[u].PB({v, r%10});
        e[v].PB({u, (1000-r)%10});
    }

    REP(i, 1, n) 
        if (!visn[i]) dfs(i);

    VLL ans(10);
    REP(i, 1, n)
        FOR(k, 10)
            ans[k] += cnt[i][k];
    
    FOR(i, 10) cout << ans[i] << endl;

    return 0;
}