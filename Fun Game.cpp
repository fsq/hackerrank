#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        VI a(n), b(n);
        vector<PII> c(n);
        FOR(i, n) cin >> a[i];
        FOR(i, n) {
            cin >> b[i];
            c[i] = {a[i], b[i]};
        }
        sort(ALL(c), [](const PII& a, const PII& b) {
            return a.first+a.second > b.first+b.second;
        });
        int sa=0, sb=0;
        FOR(i, n) 
            if (i&1) sb += c[i].second;
                else sa += c[i].first;
        cout << (sa==sb ? "Tie" : (sa>sb ? "First" : "Second")) << endl;

    }
    return 0;
}