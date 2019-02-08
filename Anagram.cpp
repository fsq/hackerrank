#include "stdc++.h"

VI count(string s) {
    VI cnt(26);
    for (auto c : s) ++cnt[c-'a'];
    return cnt;
}

int main() {
    int q;
    cin >> q;
    string s;
    while (q--) {
        cin >> s;
        if (s.size() & 1)
            cout << -1 << endl;
        else {
            int ans = 0;
            VI a = count(s.substr(0, s.size()/2)),
               b = count(s.substr(s.size()/2));
            for (int i=0; i<26; ++i)
                if (a[i]>b[i]) 
                    ans += a[i] - b[i];
            cout << ans << endl;
        }
    }
    return 0;
}