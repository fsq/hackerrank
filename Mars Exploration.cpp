#include "stdc++.h"

int main() {
    string s;
    cin >> s;
    int ans = 0;
    string sos = "SOS";
    FORI(i, s)
        if (s[i]!=sos[i%3]) 
            ++ans;
    cout << ans << endl;
    return 0;
}