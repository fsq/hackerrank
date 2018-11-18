#include "stdc++.h"

int t, n, g;
int a[103];
bool f[103][10003];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;

    while (t--) {
        int sum = 0;
        MEMSET(f, false);

        cin >> n >> g;
        REP(i, 1, n) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum > 2*g) {
            cout << "NO\n";
            continue;
        } else if (sum <= g) {
            cout << "YES\n";
            continue;
        }

        f[0][0] = true;
        REP(i, 1, n) {
            f[i][0] = true;
            REP(j, 1, g)
                f[i][j] = f[i-1][j] || (j>=a[i] && f[i-1][j-a[i]]);
        }

        int big = 0;
        PER(j, g, 0)
            if (f[n][j]) {
                big = j;
                break;
            }
        if (sum-big<=g) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}