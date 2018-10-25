#include "stdc++.h"

const LL M = 1e9 + 7;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    if (k==2)
        cout << ((n&1) ^ 1) << endl;
    else if (n==3)
        cout << k-2 << endl;
    else {

        // tot[n] = #ways to generate length n seq
        // f[n][x] = #ways to generate length n seq ends with x
        // f[n][x] = tot[n-1]-f[n-1][x]

        LL tot = 1;
        LL f = x == 1;
        REP(i, 2, n) {
            f = (tot - f + M) % M;
            tot = tot * (k-1) % M;
        }
        cout << f << endl;
    }

    return 0;
}