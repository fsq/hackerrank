#include "stdc++.h"

unordered_map<LL, PII> m;
LL a[20000], s[20000];

int dp(int l, int r) {
    if (r-l+1<=1) return 0;
    auto sum = s[r] - s[l-1];
    if ((sum&1) || !m.count(s[l-1]+(sum>>1))) return 0;
    auto pr = m[s[l-1] + (sum>>1)];
    return 1 + max(dp(l, pr.first), dp(pr.second+1, r));
}

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    s[0] = 0;
    while (t--) {
        cin >> n;
        m.clear();
        MEMSET(a, 0);
        REP(i, 1, n) {
            cin >> a[i];
            s[i] = s[i-1] + a[i];
            if (m.count(s[i]))
                m[s[i]].second = i;
            else
                m[s[i]] = {i, i};
        }

        cout << (s[n]==0 ? n-1 : dp(1, n)) << endl;
    }
    return 0;
}