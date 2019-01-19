#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    FOR(i, n) cin >> a[i];

    sort(ALL(a), [](const string& a, const string& b) {
        return SZ(a) < SZ(b) || (SZ(a)==SZ(b) && a<b);
    });
    FOREACH(&s, a) cout << s << endl;
    return 0;
}