#include "stdc++.h"

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i=0, j=s.size()-1; i<j; ++i,--j)
            ans += abs(s[i]-s[j]);
        cout << ans << endl;
    }
    return 0;
}