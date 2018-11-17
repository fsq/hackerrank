#include "stdc++.h"

int n, k;
const LL M = 1e9 + 7;

int main() {
    cin >> n >> k;
    VVLL f(n+1, VLL(k+1));
    VLL s(k+1);
    f[1][0] = 1;
    REP(i, 2, n) 
        if (i==2) {
            fill(f[2].begin(), f[2].end(), 1);
            iota(s.begin(), s.end(), 1);
        } else {
            f[i][0] = 1;
            REP(j, 1, k) 
                f[i][j] = (s[j] - (j-(i-1)<=0 ? 0 : s[j-(i-1)-1])+M) % M;
            REP(j, 1, k)
                s[j] = (s[j-1] + f[i][j]) % M;
        }

    cout << f[n][k] << ' ';

    REP(i, 2, n) 
        if (i==2) {
            f[2][0] = 1;
            fill(f[2].begin()+1, f[2].end(), 2);
        } else {
            f[i][0] = 1;
            REP(j, 1, k)
                f[i][j] = (f[i-1][j] + (i-1)*f[i-1][j-1]) % M;
        }
    cout << f[n][k] << endl;
    return 0;
}