#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    set<LL> st;
    LL ans = 1e16, x;
    while (n--) {
        cin >> x;
        auto it = st.upper_bound(x);
        if (it!=st.end()) {
            ans = min(ans, *it-x);
            if (ans==0) break;
        }
        st.insert(x);
    }

    cout << ans << endl;

    return 0;
}