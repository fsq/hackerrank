#include "stdc++.h"

const int M = 1e9 + 7;

bool isPrime(int x) {
    for (int i=2; i<=sqrt(x); ++i)
        if (x % i==0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int q, n;
    cin >> q;

    VLL pre(8200), f(8200);
    VI prime;
    REP(i, 2, 8191)
        if (isPrime(i))
            prime.PB(i);

    while (q--) {
        cin >> n;
        unordered_map<int, int> a;

        for (int x,i=0; i<n; ++i) {
            cin >> x;
            ++a[x];
        }

        FILL0(pre);
        pre[0] = 1;

        for (auto& kv : a) {
            int x = kv.first, c = kv.second;
            REP(p, 0, 8191) {
                f[p] = pre[p] * (c/2+1) % M;
                f[p] = (f[p] + pre[p^x] * ((c-1)/2+1) % M) % M;
            }
            pre.swap(f);
        }

        LL ans = 0;
        for (auto& p : prime)
            ans = (ans+pre[p]) % M;
        cout << ans << endl;

    }
    return 0;
}