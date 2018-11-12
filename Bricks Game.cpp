#include "stdc++.h"

LL a[100007], f[100007], s[100007];

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    MEMSET(a, 0);
    MEMSET(f, 0);
    MEMSET(s, 0);

    while (t--) {
        LL sum = 0;
        cin >> n;
        REP(i, 1, n) cin >> a[i];
        s[n+1] = f[n+1] = 0;

        PER(i, n, 1) {
            s[i] = s[i+1] + a[i];
            f[i] = a[i] + (s[i+1]-f[i+1]);
            if (i+1<=n)
                f[i] = max(f[i], a[i]+a[i+1]+(s[i+2]-f[i+2]));
            if (i+2<=n)
                f[i] = max(f[i], a[i]+a[i+1]+a[i+2]+(s[i+3]-f[i+3]));
        }
        cout << f[1] << '\n';
        
    }

    return 0;
}