#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    unordered_map<LL, int> cnt;

    LL x, ans = 0;
    while (n--) {
        cin >> x;
        if (cnt.count(x+k)) ans += cnt[x+k];
        if (cnt.count(x-k)) ans += cnt[x-k];
        ++cnt[x];
    }

    cout << ans << endl;
    return 0;
}