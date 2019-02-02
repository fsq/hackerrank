#include "stdc++.h"

int main() {
    int n, ans=0;
    cin >> n;
    string s;
    cin >> s;

    for (int i=0; i+3<=n; ++i)
        if (s[i]=='0' && s[i+1]=='1' && s[i+2]=='0') {
            s[i+2] = '1';
            ++ans;
        }
    cout << ans << endl;
    return 0;
}