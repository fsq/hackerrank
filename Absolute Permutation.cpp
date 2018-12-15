#include "stdc++.h"

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k==0)
            REP(i, 1, n) cout << i << ' ';
        else if (n%(2*k)==0) {
            REP(i, 1, n)
                if ((i-1)%(2*k)<k) cout << i+k << ' ';
                    else       cout << i-k << ' ';
        } else 
            cout << "-1";
        cout << '\n';

    }
    return 0;
}