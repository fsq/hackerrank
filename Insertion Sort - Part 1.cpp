#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(n);
    FOR(i, n) cin >> a[i];
    int x = a.back();
    PER(i, n-2, 0) 
        if (a[i]>x) {
            a[i+1] = a[i];
            FOREACH(x, a) cout << x << ' '; cout << endl;
            if (i==0) a[i] = x;
        } else {
            a[i] = x;
            break;
        }
    FOREACH(x, a) cout << x << ' '; cout << endl;    
    return 0;
}