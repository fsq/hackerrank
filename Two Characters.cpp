#include "stdc++.h"

int main() {
    int n;
    string s;
    cin >> n >> s;
    VVI a(26);
    FORI(i, s)
        a[s[i]-'a'].PB(i);
    
    int ans = 0;
    FOR(i, 26) REP(j, i+1, 25) 
        if (SZ(a[i]) && SZ(a[j]) && abs(SZ(a[i])-SZ(a[j]))<=1) {
            VI& x = a[i].front()<a[j].front() ? a[i] : a[j];
            VI& y = a[i].front()<a[j].front() ? a[j] : a[i];
            if (SZ(x)<SZ(y)) continue;
            bool ok = true;
            FORI(k, y) 
                if (!(x[k]<y[k] && (k+1==SZ(x) || x[k+1]>y[k]))) {
                    ok = false;
                    break;
                }
            if (ok)
                ans = max(ans, SZ(x)+SZ(y));
        }
    cout << ans << endl;

    return 0;
}