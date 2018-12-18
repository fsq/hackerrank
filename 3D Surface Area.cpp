#include "stdc++.h"

VI dx = {-1, 0, 1, 0};
VI dy = {0, 1, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;
    VVI a(n+2, VI(m+2));
    
    REP(i, 1, n) REP(j, 1, m) cin >> a[i][j];
    int ans = 2 * n * m;

    REP(i, 1, n) REP(j, 1, m)
        FOR(dir, 4) {
            int tx=i+dx[dir], ty=j+dy[dir];
            if (a[i][j]>a[tx][ty])
                ans += a[i][j] - a[tx][ty];
        }
    cout << ans << endl;
    return 0;
}