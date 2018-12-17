#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        VI a(n+1), pos(n+1);

        bool ok = true;
        REP(i, 1, n) {
            cin >> a[i];
            if (a[i]<1 || a[i]>n) {
                ok = false;
                goto last;
            }
            pos[a[i]] = i;
        }

        REP(i, 1, n-2) 
            if (a[i] != i) {
                int x = i+1;
                while (a[x]!=i) ++x;
                if ((x-i) & 1) 
                    if (x<n) {
                        int t = a[x-1];
                        a[x-1] = a[x];
                        a[x] = a[x+1];
                        a[x+1] = t;
                        --x;
                    } else {
                        int t = a[x-2];
                        a[x-2] = a[x-1];
                        a[x-1] = a[x];
                        a[x] = t;
                        --x;
                    }
                a.erase(a.begin()+x);
                a.insert(a.begin()+i, i);
            }
        if (a[n-1]+1 != a[n]) ok = false;

        last:
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}