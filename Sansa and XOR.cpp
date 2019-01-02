#include "stdc++.h"

int main() {
    int t, x;
    LL n;
    cin >> t;
    while (t--) {
        cin >> n; 
        int s = 0;
        FOR(i, n) {
            cin >> x;
            LL cnt = (i+1) * (n-i);
            if (cnt&1) s ^= x;
        }
        cout << s << endl;

    }    
    return 0;
}