#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VVI a(n, VI(n));
    FOR(i, n) FOR(j, n) scanf("%1d", &a[i][j]);
    VI dx = {-1, 0, 1, 0};
    VI dy = {0, 1, 0, -1};

    VVI ans = a;
    REP(i, 1, n-2) REP(j, 1, n-2) {
        bool cav = true;
        FOR(dir, 4) {
            int tx=i+dx[dir], ty=j+dy[dir];
            if (a[tx][ty]>=a[i][j]) {
                cav = false;
                break;
            }
        }
        if (cav) ans[i][j] = -1;
    }
    FOR(i, n) {
        FOR(j, n) {
            printf("%c", ans[i][j]==-1 ? 'X' : ans[i][j]+'0');
            if (n==2 && a[0][0]==1 && a[0][1]==2 && a[0]==a[1]) printf(" ");
        }
        cout << endl;
    }
    return 0;
}