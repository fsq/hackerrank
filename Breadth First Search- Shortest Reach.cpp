#include "stdc++.h"

int main() {
    int q, n, m, s;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        VVI e(n+1);
        for (int u,v,i=0; i<m; ++i) {
            cin >> u >> v;
            e[u].PB(v);
            e[v].PB(u);
        }
        
        VI d(n+1, -1);
        queue<int> q;
        cin >> s;
        d[s] = 0;
        q.push(s);

        while (q.size()) {
            int u = q.front(); q.pop();
            FOREACH(v, e[u])
                if (d[v]==-1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
        }
        REP(i, 1, n) 
            if (i!=s) 
                cout << (d[i]==-1 ? -1 : d[i]*6) << ' ';
        cout << endl;
    }
    return 0;
}