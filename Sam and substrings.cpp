#include "stdc++.h"

const LL M = 1e9 + 7;

LL myPow(LL a, int b) {
    if (b==0) return 1;
    if (b==1) return a;
    LL h = myPow(a, b>>1);
    return (b&1) ? h*h%M*a%M : h*h%M;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();

    VLL p(n+1);
    p[0] = 1;
    REP(i, 1, n) 
        p[i] = (p[i-1]*10) % M;

    LL dv = myPow(9, M-2);

    LL ans = 0;
    FOR(i, n) {
        int x = s[i] - '0';
        int t = n - i;
        ans += x*(i+1) % M * (p[t]-1+M)%M * dv%M;
        ans %= M;
    }
    cout << ans << endl;

    return 0;
}