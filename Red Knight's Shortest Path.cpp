#include "stdc++.h"

vector<string> direction = {"UL","UR", "R", "LR", "LL", "L"};
VI dx = {-2, -2, 0, 2, 2, 0};
VI dy = {-1, 1, 2, 1, -1, -2};
vector<PII> pre, q;

void print(int i) {
    if (i==0) return;
    print(pre[i].first);
    cout << direction[pre[i].second] << ' ';
}

int main() {
    int n, sx, sy, px, py;
    cin >> n >> sx >> sy >> px >> py;

    pre.PB({0,0});
    VVI vis(n, VI(n, -1));
    vis[sx][sy] = 0;
    q.PB({sx, sy});

    for (int x,y,tx,ty,i=0; i<q.size(); ++i) {
        tie(x, y) = q[i];
        FOR(dir, 6) {
            tx = x+dx[dir], ty = y+dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<n && vis[tx][ty]==-1) {
                vis[tx][ty] = vis[x][y] + 1;
                pre.PB({i, dir});
                q.PB({tx, ty});
                if (tx==px && ty==py)
                    goto outer;
            }
        }
    }
    outer:
    if (vis[px][py] != -1) {
        cout << vis[px][py] << endl;
        print(q.size()-1);
        cout << endl;
    } else
        cout << "Impossible\n";

    return 0;
}