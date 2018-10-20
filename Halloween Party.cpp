#include "stdc++.h"

int n, m, a, b;
const int M = 1e9 + 7;

int f[53][53][53][53];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> b;

    f[1][1][0][0] = 1;

    REP(k1, 0, a) 
    REP(k2, 0, b)
    REP(i, 1, n)
    REP(j, 1, m) 
        if (!(i==1 && j==1 && k1==0 && k2==0)) {
            f[i][j][k1][k2] = (f[i-1][j][k1][k2]+f[i][j-1][k1][k2]) % M;
            if (k1>0 && i<n && !(i+1==n && j==m)) 
                f[i][j][k1][k2] = (f[i][j][k1][k2]+f[i+1][j][k1-1][k2]) % M;
            if (k2>0 && j<m && !(j+1==m && i==n))
                f[i][j][k1][k2] = (f[i][j][k1][k2]+f[i][j+1][k1][k2-1]) % M;
        }

    int ans = 0;
    REP(k1, 0, a)
    REP(k2, 0, b)
        ans = (ans + f[n][m][k1][k2]) % M;
    cout << ans << endl;
    return 0;
}