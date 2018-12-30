#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    VI a(n);
    FOR(i, n) cin >> a[i];

    int ans = 0, pre = INT_MIN;
    for (int nxt, j,i=0; i<n; ) {
        nxt = -1;
        for (j=i; j<n && j<i+k; ++j) 
            if (a[j]==1)
                nxt = j;
        if (nxt==-1) {
            if (pre+k > i) {
                ++ans;
                i = pre + k;
            } else {
                ans = -1;
                break;
            }
        } else {
            i = nxt + k;
            ++ans;
            for (; nxt<n && nxt<i; ++nxt)
                if (a[nxt])
                    pre = nxt;
        }
    }
    cout << ans << endl;
    return 0;
}