#include "stdc++.h"

const int N = 100000;

int main() {
    VI p, vis(N+1);
    REP(i, 2, N) {
        if (!vis[i]) p.PB(i);
        for (int j=0; j<SZ(p) && p[j]*i<=N; ++j) {
            vis[p[j]*i] = true;
            if (i%p[j]==0) break;
        }
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int i = upper_bound(ALL(p), n) - begin(p);
        cout << ((i&1) ? "Alice" : "Bob") << endl;
    }

    return 0;
}