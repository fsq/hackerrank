#include "stdc++.h"

const int INF = 0x3f3f3f3f;

int main() {
    int n, m, src, dst;
    cin >> n >> m;

    vector<vector<PII>> a(n+1);
    for (int u,v,c,i=0; i<m; ++i) {
        cin >> u >> v >> c;
        a[u].PB({v, c});
        a[v].PB({u, c});
    }
    cin >> src >> dst;

    VVI vis(n+1, VI(2048));
    VI d(n+1, INF);
    queue<pair<int,int>> q;
    q.push({src, 0});
    vis[src][0] = true;
    d[src] = 0;

    while (!q.empty()) {
        int u, dis;
        tie(u, dis) = q.front(); 
        q.pop();
        FOREACH(&pr, a[u])
            if (!vis[pr.F][pr.S | dis]) {
                vis[pr.F][pr.S | dis] = true;
                q.push({pr.F, pr.S | dis});
                d[pr.F] = min(d[pr.F], pr.S | dis);
            }
    }

    cout << (d[dst]==INF ? -1 : d[dst]) << endl;

    return 0;
}