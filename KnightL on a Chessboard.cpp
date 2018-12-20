#include "stdc++.h"

int solve(int n, int i, int j) {
    VI dx = {-i, -j, -j, -i, i, j, j, i};
    VI dy = {-j, -i, i, j, j, i, -i, -j};

    VVI vis(n+1, VI(n+1));
    queue<pair<int,int>> q;
    q.push({1, 1});
    vis[1][1] = true;

    for (int step=1; q.size(); ++step) {
        for (int x,y,tx,ty,sz=q.size(); sz; --sz) {
            tie(x, y) = q.front();
            q.pop();
            FOR(dir, 8) {
                tx = x+dx[dir], ty = y+dy[dir];
                if (tx>=1 && tx<=n && ty>=1 && ty<=n && !vis[tx][ty]) {
                    if (tx==n && ty==n) return step;
                    vis[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    VVI ans(n, VI(n, -1));
    REP(i, 1, n-1) REP(j, i, n-1) 
        ans[i][j] = ans[j][i] = solve(n, i, j);

    REP(i, 1, n-1) {
        REP(j, 1, n-1) cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}