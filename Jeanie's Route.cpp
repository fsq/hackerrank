#include "stdc++.h"

#define HASKEY(x) (color[x] || subsum[x])

int n, k, ans;
VI color, subsum, sum, sublg, lg, uplg;
vector<vector<PII>> e;

void dfs(VI& vis, int x) {
    int y, d;
    vis[x] = true;
    FOREACH(&edge, e[x]) {
        tie(y, d) = edge;
        if (!vis[y]) {
            dfs(vis, y);
            if (HASKEY(y)) {
                subsum[x] += subsum[y] + 2*d;
                sublg[x] = max(sublg[x], sublg[y]+d);
            }
        }
    }
}

void dfs1(VI& vis, int x) {
    int y, d;
    vis[x] = true;
    lg[x]  = max(sublg[x], uplg[x]);
    ans = min(ans, sum[x]-lg[x]);

    VI len, ds;
    FOREACH(&edge, e[x]) {
        tie(y, d) = edge;
        if (!vis[y] && HASKEY(y)) {
            len.PB(sublg[y]+d);
            ds.PB(d);
        }
    }
    if (len.empty()) return;

    VI tail(len.size()+1);
    PER(i, SZ(tail)-2, 0) tail[i] = max(tail[i+1], len[i]);

    int i = 0, premax = 0;
    FOREACH(&edge, e[x]) {
        tie(y, d) = edge;
        if (!vis[y] && HASKEY(y)) {
            int rlg = max(max(premax, tail[i+1]), uplg[x]);
            uplg[y] = rlg==0 ? color[x]*d : rlg+d;
            sum[y] = uplg[y]==0 ? sum[x]-2*ds[i] : sum[x];
            dfs1(vis, y);
            premax = max(premax, len[i++]);
        }
    }
}

int main() {
    cin >> n >> k;

    color = subsum = sum = sublg = lg = uplg = VI(n+1);
    e.resize(n+1);
    for (int x,i=0; i<k; ++i) {
        cin >> x;
        color[x] = true;
    }

    for (int u,v,d,i=0; i+1<n; ++i) {
        cin >> u >> v >> d;
        e[u].PB({v,d}), e[v].PB({u,d});
    }

    VI vis(n+1);
    dfs(vis, 1);

    FILL(vis, false);
    sum[1] = subsum[1];
    ans = INT_MAX;
    dfs1(vis, 1);

    cout << ans << endl;

    return 0;
}