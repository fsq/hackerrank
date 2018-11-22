#include "stdc++.h"

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        vector<PII> q(n+1);
        REP(i, 1, n) 
            cin >> q[i].first >> q[i].second;

        VVI f(n+1, VI(m+1, INF));
        REP(i, 1, m) f[1][i] = abs(q[1].first-q[1].second);
        REP(i, 1, n-1) REP(j, 1, m)
            if (f[i][j]!=INF) {
                f[i+1][j] = min(f[i+1][j], 
                                f[i][j]+abs(q[i+1].first-q[i].second)+abs(q[i+1].first-q[i+1].second));
                f[i+1][q[i].second] = min(f[i+1][q[i].second], 
                                f[i][j]+abs(q[i+1].first-j)+abs(q[i+1].first-q[i+1].second));
            }
        int ans = *min_element(f[n].begin(), f[n].end());
        cout << ans << endl;
    }
    return 0;
}