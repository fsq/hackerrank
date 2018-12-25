#include "stdc++.h"

VI dx = {-1, -1, -1, 0, 1, 1, 1, 0};
VI dy = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(VVI& a, int x, int y, int& area) {
    ++area;
    a[x][y] = 0;

    FOR(dir, 8) {
        int tx=x+dx[dir], ty=y+dy[dir];
        if (tx>0 && tx<a.size() && ty>0 && ty<a[0].size() && a[tx][ty]) 
            dfs(a, tx, ty, area);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    VVI a(n+1, VI(m+1));
    REP(i, 1, n) REP(j, 1, m) cin >> a[i][j];

    int ans = 0;
    REP(i, 1, n) REP(j, 1, m)
        if (a[i][j]) {
            int area = 0;
            dfs(a, i, j, area);
            ans = max(area, ans);
        }
    cout << ans << endl;
    return 0;
}