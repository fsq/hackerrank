#include "stdc++.h"

int main() {
    int n, d;
    cin >> n >> d;
    VI a(n+1);
    multiset<int> st;

    REP(i, 1, d) {
        cin >> a[i];
        st.insert(a[i]);
    }
    auto it = st.begin();
    advance(it, d/2);

    int ans = 0;
    REP(i, d+1, n) {
        cin >> a[i];
        int med2 = (d&1) ? *it*2 : (*prev(it) + *it);
        if (a[i]>=med2) ++ans;

        st.insert(a[i]);
        if (a[i]<*it) --it;

        int del = a[i-d];
        if (del<=*it) ++it;
        st.erase(st.lower_bound(del));
    }

    cout << ans << endl;
    return 0;
}