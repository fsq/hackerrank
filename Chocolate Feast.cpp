#include "stdc++.h"

int main() {
    int t, n, c, m;
    cin >> t;
    while (t--) {
        cin >> n >> c >> m;
        int ans=0, wp=0;
        ans = wp = n/c;
        while (wp>=m) {
            ans += wp / m;
            wp = wp/m + wp%m;
        }
        cout << ans << endl;
    }
    return 0;
}