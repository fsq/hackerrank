#include "stdc++.h"

int s[220000];

void init() {
    VI p;
    REP(i, 2, 218000) {
        if (!s[i]) 
            p.PB(i);
        for (int j=0; j<p.size() && p[j]*i<=218000; ++j) {
            s[p[j]*i] = 1;
            if (i % p[j]==0) break;
        }
    }
    REP(i, 2, 218000)
        s[i] = s[i-1] + !s[i];
}

int main() {
    int t, n;

    init();

    cin >> t;
    while (t--) {
        cin >> n;
        VI f(n+1);
        f[0] = 1;
        REP(i, 1, n)
            f[i] = f[i-1] + (i>=4 ? f[i-4] : 0);
        cout << s[f[n]] << endl;
    }
    return 0;
}