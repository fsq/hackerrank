#include "stdc++.h"

const int N = 403;
int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    MEMSET(a, 0x3f);

    for (int u,v,x,i=0; i<m; ++i) {
        cin >> u >> v >> x;
        a[u][v] = x;
    }   

    REP(i, 1, n) a[i][i] = 0;

    REP(k, 1, n)
        REP(i, 1, n)
            REP(j, 1, n)
                if (i!=j && a[i][k]+a[k][j]<a[i][j])
                    a[i][j] = a[i][k] + a[k][j];


    int q;
    cin >> q;
    for (int u,v,i=0; i<q; ++i) {
        cin >> u >> v;
        cout << (a[u][v]==0x3f3f3f3f ? -1 : a[u][v]) << endl;
    }
    return 0;
}