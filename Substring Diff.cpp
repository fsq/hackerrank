#include "stdc++.h"

int k, t, n;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> k >> a >> b;
        n = a.size();
        a.insert(a.begin(), ' ');
        b.insert(b.begin(), ' ');
        int ans = 0;
        REP(ofst, 1-n, n-1) {
            int la=1, lb=1;
            if (ofst<0) 
                lb = -ofst;
            else 
                la = ofst;
            for (int i=la, j=lb, df=0; i<=n && j<=n; ++i,++j) {
                df += a[i] != b[j];
                while (df>k) 
                    if (a[la++]!=b[lb++])
                        --df;
                ans = max(ans, i-la+1);
            }
        }
        cout << ans << endl;

    }
    return 0;
}