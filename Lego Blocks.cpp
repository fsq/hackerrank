#include "stdc++.h"

int t, h, w;
const LL M = 1e9 + 7;
LL row[1003], p[1003][1003];
VLL f, g;

void preprocess() {
    MEMSET(row, 0);
    row[0] = 1;
    REP(i, 1, 1000) {
        REP(j, max(0, i-4), i-1) 
            row[i] = (row[i] + row[j]) % M;
        p[i][0] = 1;
        REP(j, 1, 1000) 
            p[i][j] = (p[i][j-1]*row[i]) % M;
    }
}

LL dpf(int);
LL dpg(int);

LL dpf(int w) { // #ways of invalid
    if (f[w]!=-1) return f[w];
    f[w] = 0;
    REP(j, 1, w-1) 
        f[w] = (f[w] + dpg(w-j)*p[j][h]%M) % M;
    return f[w];
}


LL dpg(int w) { // #ways of valid
    if (g[w]!=-1) return g[w];
    return g[w] = (p[w][h] - dpf(w) + M) % M;
}

int main() {
    preprocess();
    cin >> t;
    while (t--) {
        cin >> h >> w;

        f = g = VLL(w+1, -1);
        f[1] = 0, g[1] = 1;
        cout << dpg(w) << endl;
    }
    return 0;
}