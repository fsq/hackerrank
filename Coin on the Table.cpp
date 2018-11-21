#include "stdc++.h"

int n, m, maxStep;
vector<string> a;
int f[1003][54][54];
const int INF = 0x3f3f3f3f;
string direction = "ULDR";
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> maxStep;

    a.resize(n+1);

    REP(i, 1, n) {
        cin >> a[i];
        a[i].insert(a[i].begin(), ' ');
    }
    int dstx=-1, dsty=-1;
    REP(i, 1, n) REP(j, 1, m) 
        if (a[i][j]=='*') 
            dstx = i, dsty = j;

    MEMSET(f, 0x3f);
    f[0][1][1] = 0;
    REP(t, 0, maxStep-1) REP(i, 1, n) REP(j, 1, m)
        if (f[t][i][j]!=INF) 
            FOR(dir, 4) {
                int tx=i+dx[dir], ty=j+dy[dir];
                if (tx>=1 && tx<=n && ty>=1 && ty<=m)
                    f[t+1][tx][ty] = min(f[t+1][tx][ty], 
                                         f[t][i][j]+(a[i][j]!=direction[dir]));
            }

    int ans = INF;
    REP(t, 0, maxStep)
        ans = min(ans, f[t][dstx][dsty]);
    cout << (ans==INF ? -1 : ans) << endl;

    return 0;
}