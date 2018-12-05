#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    int mx, mn;
    cin >> mx;
    mn = mx;

    int ans1=0, ans2=0;
    for (int x,i=0; i+1<n; ++i) {
        cin  >> x;
        if (x>mx) {
            mx = x;
            ++ans1;
        }
        if (x<mn) {
            mn = x;
            ++ans2;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}