#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        VLL a(n);
        FOR(i, n) cin >> a[i];
        if (n==1) {
            LL x = a[0];
            a.pop_back();
            a.PB(1), a.PB(1);
            if (x>1) a.PB(x-1);
        } else if (n==2) {
            LL x = a[0], y = a[1];
            a.clear();
            a.PB(1), a.PB(y+1);
            if (x>1) a.PB(x-1);
        } else if (n&1) {
            LL x = a[n-2], y = a[n-1];
            a.pop_back(), a.pop_back();
            if (x==1) 
                ++a.back();
            else
                a.PB(x-1), a.PB(1);
            a.PB(1);
            if (y>1) a.PB(y-1);
        } else {
            LL x = a[n-3], y = a[n-2], z = a[n-1];
            a.pop_back(), a.pop_back(), a.pop_back();
            if (x==1)
                ++a.back();
            else 
                a.PB(x-1), a.PB(1);
            a.PB(z+1);
            if (y>1) a.PB(y-1);
        }
        cout << a.size() << '\n';
        FOR(i, SZ(a)-1) cout << a[i] << ' ';
        cout << a.back() << '\n';
    }
    return 0;
}