#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<PII> a(n);
        FOR(i, n) 
            cin >> a[i].first >> a[i].second;

        sort(a.begin(), a.end(), [](const PII& a, const PII& b) {
            return a.second<b.second || (a.second==b.second && a.first>b.first);
        });

        vector<PII> ans;
        int lap2 = -1;
        for (auto& it : a) 
            if (it.first>lap2) {
                if (ans.size() && it.first<=ans.back().second) 
                    lap2 = ans.back().second;

                ans.push_back(it);
            }

        cout << ans.size() << endl;
    }
    return 0;
}