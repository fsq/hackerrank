#include "stdc++.h"

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    FOR(i, n) cin >> a[i];

    VVI s(n, VI(m));
    int ans = 0;

    FOR(i, n) FOR(j, m) 
        if (a[i][j]=='G') 
            for (int l=0; i+l<n & i-l>=0 && j+l<m && j-l>=0 && 
                 a[i][j+l]=='G' && a[i][j-l]=='G' && a[i+l][j]=='G' && a[i-l][j]=='G';
                 ++l)
                s[i][j] = l;

    FOR(i, n) FOR(j, m) FOR(x, n) FOR(y, m)
        if (!(i==x && j==y) && a[i][j]=='G' && a[x][y]=='G')  
            if (i!=x && j!=y) {
                int dis = min(abs(i-x), abs(j-y));
                REP(l, 0, s[i][j]) {
                    int ar1 = 1 + 4*l;
                    int sd = s[x][y];
                    if (l>=abs(j-y)) sd = min(sd, abs(i-x)-1);
                    if (l>=abs(i-x)) sd = min(sd, abs(j-y)-1);
                    int ar2 = 1 + 4*sd;
                    ans = max(ans, ar1 * ar2);
                }
            } else {
                int lt = 0, dis;
                if (i==x) {
                    dis = abs(i-x) - 1;
                } else 
                    dis = abs(j-y) - 1;
                int mult;
                if (s[x][y]+s[i][j]<=dis)
                    mult = (1+4*s[x][y]) * (1+4*s[i][j]);
                else 
                    REP(l, 0, s[i][j]) {
                        mult = (1+4*l) * (1+4*min(s[x][y], dis-l));
                        ans = max(ans, mult);
                    }
            }


    cout << ans << endl;
    return 0;
}