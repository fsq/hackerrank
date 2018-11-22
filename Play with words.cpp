#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), ' ');
    VVI f(n+1, VI(n+1));

    REP(i, 1, n) f[i][i] = 1;
    REP(l, 2, n) 
        REP(i, 1, n-l+1) {
            int j = i + l - 1;
            f[i][j] = max(f[i+1][j], f[i][j-1]);
            if (s[i]==s[j])
                f[i][j] = max(f[i][j], f[i+1][j-1]+2);
        }

    int ans = 0;
    REP(i, 1, n-1) 
        ans = max(ans, f[1][i]*f[i+1][n]);
    cout << ans << endl;
    return 0;
}