#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, x = n;
        while (x) {
            int p = x % 10;
            if (p!=0 && n%p==0)
                ++ans;
            x /= 10;
        }
        cout << ans << endl;

    }
    return 0;
}