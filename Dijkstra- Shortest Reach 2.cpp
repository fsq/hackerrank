#include "stdc++.h"

const int N = 3007;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N][N];
int d[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    int t, s;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        MEMSET(a, INF);
        MEMSET(d, INF);
        MEMSET(vis, 0);
        for (int u,v,r,i=0; i<m; ++i) {
            cin >> u >> v >> r;
            a[v][u] = a[u][v] = min(a[u][v], r);
        }

        cin >> s;
        d[s] = 0;
        REP(_t, 1, n) {
            int mind = INF, u;
            REP(i, 1, n)
                if (!vis[i] && d[i] < mind) {
                    mind = d[i];
                    u = i;
                }
            vis[u] = true;
            REP(v, 1, n) 
                if (d[u]+a[u][v] < d[v]) 
                    d[v] = d[u] + a[u][v];              
        }

        REP(i, 1, n)
            if (i!=s)
                cout << (d[i]==INF ? -1 : d[i]) << ' ';
        cout << '\n';

    }
    return 0;
}