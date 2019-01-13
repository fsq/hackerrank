#include "stdc++.h"

int rev(int x) {
    int y = 0;
    while (x) {
        y = y*10 + x%10;
        x /= 10;
    }
    return y;
}

int main() {
    int s, t, k;
    cin >> s >> t >> k;
    int ans = 0;
    REP(x, s, t)
        if (abs(x-rev(x))%k==0)
            ++ans;
    cout << ans << endl;
    return 0;
}