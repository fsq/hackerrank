#include "stdc++.h"

int a[507][507];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    MEMSET(a, 0);

    string s;
    REP(i, 1, n) {
        cin >> s;
        REP(j, 1, m) 
            a[i][j] = s[j-1]=='.';
    }

    int ans = 0;
    REP(up, 1, n) {
        VI s(m+1);
        REP(i, 1, m) s[i] = a[up][i];
        REP(lo, up+1, n) {
            int pre = 0;
            REP(i, 1, m) {
                s[i] &= a[lo][i];
                if (!pre) {
                    if (s[i]) pre = 1;
                } else {
                    if (!(a[up][i] && a[lo][i]))
                        pre = 0;
                    else {
                        ++pre;
                        if (s[i])
                            ans = max(ans, (lo-up+1)*2 + (pre-2)*2);
                    }
                }
            }
        }
    }

    if (ans>0)
        cout << ans << endl;
    else
        cout << "impossible" << endl;

    return 0;
}