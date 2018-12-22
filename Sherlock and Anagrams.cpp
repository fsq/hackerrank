#include "stdc++.h"

int main() {
    int n, q;
    cin >> q;
    string s;
    while (q--) {
        cin >> s;
        n = s.size();
        int ans = 0;
        for (int l=1; l<n; ++l) {
            map<vector<int>, int> m;
            vector<int> cnt(26);
            for (int i=0; i<n; ++i) {
                ++cnt[s[i]-'a'];
                if (i-l>=0) --cnt[s[i-l]-'a'];
                ++m[cnt];
            }
            for (auto& kv : m)
                ans += kv.second * (kv.second-1) >> 1;
        }
        cout << ans << endl;
    }
    return 0;
}