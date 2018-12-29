#include "stdc++.h"

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> e(n+1);
    for (int u,v,w,i=0; i<m; ++i) {
        cin >> u >> v >> w;
        e[u].PB({v, w});
        e[v].PB({u, w});
    }

    VI vis(n+1), dis(n+1, INT_MAX);
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (q.size()) {
        while (q.size() && vis[q.top().second])
            q.pop();
        if (q.empty()) break;

        int d, u;
        tie(d, u) = q.top(); q.pop();
        vis[u] = true;
        if (u==n) break;

        FOREACH(&eg, e[u]) 
            if (!vis[eg.first]) {
                int v = eg.first, w = eg.second;
                int nd = w>=dis[u] ? w : dis[u];
                if (nd<dis[v]) {
                    dis[v] = nd;
                    q.push({nd, v});
                }
            }
    }

    cout << (dis[n]==INT_MAX ? "NO PATH EXISTS" : to_string(dis[n])) << endl;
    return 0;
}