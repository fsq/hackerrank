/*
f[n] = \sum_{i=0}^{n-1} f[i] + g[i]*s[i+1~n]*(n-i)
where g[n] = #partitions for length n array 
      g[0] = 1;
      g[i] = 2^{i-1}

observe term g[i]*(s[n]-s[i])*(n-i)
           = g[i]*(s[n]*n-s[n]*i-s[i]*n+s[i]*i)

    calc \sum_{i=0}^{n-1} g[i]*(s[n]*n-s[n]*i-s[i]*n+s[i]*i)
    ==>  s[n]*n* \sum_{i=0}^{n-1} g[i]
        -s[n]* \sum_{i=0}^{n-1} g[i]*i
        -n* \sum_{i=0}^{n-1} g[i]*s[i]
        +\sum_{i=0}^{n-1} g[i]*s[i]*i
    
    precompute each term 
*/


#include "stdc++.h"

int n;
VLL a, g, s, gi, gs, gsi;
const LL M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a = g = s = gi = gs = gsi = VLL(n+1);

    REP(i, 1, n) {
        cin >> a[i];
        s[i] = (s[i-1] + a[i]) % M;
    }

    g[0] = g[1] = 1;
    REP(i, 2, n) g[i] = (g[i-1]<<1) % M;

    REP(i, 0, n) {
        gi[i] = (g[i] * i) % M;
        gs[i] = (g[i] * s[i]) % M;
        gsi[i] = (g[i] * s[i]%M * i) % M;
    }

    REP(i, 1, n) {
        g[i] = (g[i-1] + g[i]) % M;
        gi[i] = (gi[i-1] + gi[i]) % M;
        gs[i] = (gs[i-1] + gs[i]) % M;
        gsi[i] = (gsi[i-1] + gsi[i]) % M;
    }

    LL sumf = 0, f = 1;
    REP(i, 1, n) {
        f = (sumf + (i*s[i]%M*g[i-1])%M - (s[i]*gi[i-1])%M+M - (gs[i-1]*i%M)+M + gsi[i-1]) % M;
        sumf = (sumf + f) % M;
    }

    cout << f << endl;


    return 0;
}