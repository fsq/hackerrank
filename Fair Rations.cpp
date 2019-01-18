#include "stdc++.h"

int main() {
    int n, x;
    cin >> n;
    VI p;
    FOR(i, n) {
        cin >> x;
        if (x&1) 
            p.PB(i);
    }
    if (p.size() & 1)
        cout << "NO\n";
    else {
        int ans = 0;
        for (int i=0; i<SZ(p); i+=2) {
            int x=p[i], y=p[i+1];
            ans += (y-x) * 2;
        }
        cout << ans << endl;
    }
    return 0;
}