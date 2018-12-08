#include "stdc++.h"

int main() {
    int n;
    string s;
    cin >> n >> s;
    int h = 0, ans = 0 ;
    for (auto c : s)
        if (c=='D') {
            --h;
            ans += h==0;
        } else 
            ++h;
    cout << ans << endl;
    return 0;
}