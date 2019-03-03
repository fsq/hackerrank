#include "stdc++.h"

int main() {
    int n, x;
    int ans = INT_MAX;
    cin >> n;
    set<int> st;
    FOR(i, n) {
        cin >> x;
        auto it = st.upper_bound(x);
        if (it != st.end()) ans = min(ans, *it-x);
        if (it != st.begin()) ans = min(ans, x-*prev(it));
        if (ans==0) break;
        st.insert(x);
    }
    cout << ans << endl;
    return 0;
}