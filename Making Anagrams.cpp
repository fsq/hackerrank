#include "stdc++.h"

VI count(const string& s) {
    VI cnt(26);
    FOREACH(c, s) ++cnt[c-'a'];
    return cnt;
}

int main() {
    string s, t;
    cin >> s >> t;
    VI a=count(s), b=count(t);

    int ans=0;
    FOR(i, 26)
        ans += abs(a[i]-b[i]);
    cout << ans << endl;
    return 0;
}