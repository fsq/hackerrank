#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    int mx = -1, ans = 0;
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        if (x==mx)
            ++ans;
        else if (x > mx) {
            mx = x;
            ans = 1;
        }
    }
    cout << ans << endl;
    return 0;
}