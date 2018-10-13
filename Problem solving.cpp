#include "stdc++.h"

int t, n, gap;
VI M, d;
VVI e;
const int INF = 0x3f3f3f3f;

void build() {
    VI a(n+1);
    REP(i, 1, n) cin >> a[i];

    M = VI(n<<1 | 1);
    d = VI(n+1);
    e = VVI(n+1);

    REP(i, 1, n)
        REP(j, i+1, n)
            if (abs(a[i]-a[j]) >= gap) 
                e[i].PB(n+j);
}

bool bfs() {
    FILL(d, INF);
    queue<int> q;
    REP(i, 1, n) 
        if (!M[i]) {
            q.push(i);
            d[i] = 0;
        }
    while (q.size()) {
        int u = q.front(); q.pop();
        if (d[u] < d[0]) 
            FOREACH(v, e[u])
                if (d[M[v]]==INF) {
                    d[M[v]] = d[u] + 1;
                    q.push(M[v]);
                }
    }
    return d[0] != INF;
}

bool dfs(int u) {
    if (!u) return true;
    int du = d[u];
    d[u] = INF;
    FOREACH(v, e[u])
        if (d[M[v]]==du+1 && dfs(M[v])) {
            M[u] = v;
            M[v] = u;
            return true;
        }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;

    while (t--) {
        cin >> n >> gap;
        build();

        int match = 0;
        while (bfs())
            REP(i, 1, n)
                match += !M[i] && dfs(i);
        cout << n - match << '\n';
    }

    return 0;
}