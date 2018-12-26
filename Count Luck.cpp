#include "stdc++.h"

int t, n, m, k;

VI dx = {-1, 0, 1, 0};
VI dy = {0, 1, 0, -1};

VI check(const vector<string>& a, int x, int y, int px, int py) {
    int count = 0;
    VI ret = {0, 0, 0};
    FOR(dir, 4) {
        int tx=x+dx[dir], ty=y+dy[dir];
        if (tx>0 && tx<=n && ty>0 && ty<=m && a[tx][ty]!='X' && 
            !(tx==px && ty==py)) {
                ++count;
                if (count==1)
                    ret = {1, tx, ty};
                else 
                    ++ret[0];
        }
    }
    return ret;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        VVI vis(n+1, VI(m+1));
        vector<string> a(n+1);
        REP(i, 1, n) {
            cin >> a[i];
            a[i].insert(a[i].begin(), ' ');
        }

        PII beg, dst; 
        REP(i, 1, n) REP(j, 1, m) 
            if (a[i][j]=='M')
                beg = {i, j};
            else if (a[i][j]=='*')
                dst = {i, j};
        
        cin >> k;

        int count = 0;
        queue<VI> q;
        q.push({beg.F, beg.S, -1, -1, 0});
        vis[beg.F][beg.S] = true;
        while (q.size()) {
            VI now = q.front(); q.pop();
            int x, y, px, py, mv;
            x = now[0], y = now[1], px = now[2], py = now[3], mv = now[4];

            VI pos = check(a, x, y, px, py);
            if (pos[0]==1) {
                q.push({pos[1], pos[2], x, y, mv});
                vis[pos[1]][pos[2]]= true;
                if (PII{pos[1], pos[2]}==dst) {
                    count = mv;
                    goto final;
                }
            } else if (pos[0]>1)
                FOR(dir, 4) {
                    int tx=x+dx[dir], ty=y+dy[dir];
                    if (tx>0 && tx<=n && ty>0 && ty<=m && a[tx][ty]!='X' && 
                        !(tx==px && ty==py) && !vis[tx][ty]) {
                        q.push({tx, ty, x, y, mv+1});
                        vis[tx][ty] = true;
                        if (PII{tx, ty}==dst) {
                            count = mv + 1;
                            goto final;
                        }
                    }
                }
        }
        final:
        cout << (count==k ? "Impressed" : "Oops!") << endl;
    }
    return 0;
}