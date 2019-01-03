#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VLL b(1<<10);
    string x;

    while (n--) {
        cin >> x;
        int s = 0;
        for (auto c : x)
            s |= 1 << (c-'0');
        ++b[s];
    }

    LL ans = 0;
    FOR(i, SZ(b)) 
        REP(j, i+1, SZ(b)-1)
            if ((i|j) == 1023)
                ans += b[i] * b[j];
    cout << ans+(b[1023]*(b[1023]-1)/2) << endl;

    return 0;
}