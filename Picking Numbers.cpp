#include "stdc++.h"

int main() {
    int n, ans = 0;
    map<int, int> m;

    cin >> n;
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++m[x];
    }

    for (auto it=m.begin(); it!=m.end(); ++it) {
        ans = max(ans, it->second);
        if (next(it)!=m.end() && next(it)->first==it->first+1)
            ans = max(ans, it->second+next(it)->second);
    }

    cout << ans << endl;
    return 0;
}