#include "stdc++.h"

const LL M = 1e9 + 7;

LL pow(LL a, LL b) {
    if (b==0) return 1;
    if (b==1) return a;
    LL hf = pow(a, b>>1);
    return (b&1) ? hf*hf%M*a%M : hf*hf%M;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), ' ');
    VVI cnt(n+1, VI(26));
    REP(i, 1, n) {
        cnt[i] = cnt[i-1];
        ++cnt[i][s[i]-'a'];
    }

    VLL fac(n/2+1), inv(n/2+1);
    fac[0] = inv[0] = 1;
    REP(i, 1, n/2) {
        fac[i] = (fac[i-1] * i) % M;
        inv[i] = pow(fac[i], M-2);
    }

    int q;
    cin >> q;

    for (int l,r,_q=0; _q<q; ++_q) {
        cin >> l >> r;
        VI a(26);
        FOR(c, 26) a[c] = cnt[r][c] - cnt[l-1][c];

        int odd = 0, tot = 0;
        VI parts;
        FOREACH(c, a)
            if (c>0) {
                odd += c & 1;
                if (c>1)parts.PB(c>>1);
                tot += c>>1;
            }
        LL ans = fac[tot];
        FOREACH(x, parts)
            ans = (ans * inv[x]) % M;
        ans = (ans * max(1, odd)) % M;
        cout << ans << endl;
    }
    return 0;
}