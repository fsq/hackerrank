#include "stdc++.h"

int a[103][103];
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    MEMSET(a, 0);
    int t, n;
    cin >> t;
    while (t--) {
        VI end(103);
        iota(end.begin(), end.end(), 0);

        FOR(t, 2) {
            cin >> n;
            for (int x,y,i=0; i<n; ++i) {
                cin >> x >> y;
                end[x] = y;
            }
        }

        REP(i, 1, 100) {
            REP(j, 1, 100) a[i][j] = INF;
            REP(j, i+1, min(100, i+6))
                a[i][end[j]] = 1;
            a[i][i] = 0;
        }

        
        
        VI d(103, INF);
        VI vis(103);
        d[1] = 0;
        REP(t, 1, 100) {
            int mind=INF, x;
            REP(i, 1, 100)
                if (!vis[i] && d[i]<mind) {
                    mind = d[i];
                    x = i;
                }
            if (mind==INF) break;
            vis[x] = true;
            REP(y, 1, 100)
                if (d[y]>d[x]+a[x][y]) 
                    d[y] = d[x] + a[x][y];
        }

        cout << (d[100]==INF ? -1 : d[100]) << endl;
    }
    return 0;
}