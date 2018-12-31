#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        VI a(n);
        FOR(i, n) cin >> a[i];

        stack<int> s;
        PER(i, n-1, 0) {
            while (s.size() && a[i]>s.top()) 
                s.pop();
            s.push(a[i]);
        }
        cout << ((s.size()&1) ? "BOB" : "ANDY") << endl;
    }
    return 0;
}