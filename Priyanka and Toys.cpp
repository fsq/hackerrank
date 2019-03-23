#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI cnt(10007);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    int ans = 0;
    for (int i=0; i<=10000; )
        if (cnt[i]) {
            ++ans;
            i += 4;
        } else 
            ++i;
    cout << ans << endl;

    return 0;
}