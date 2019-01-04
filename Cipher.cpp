#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;
    string s, a;
    cin >> s;
    n = s.size() - k + 1;
    a.PB(s[0]);
    REP(i, 1, n-1)
        if (i<k)
            a.PB(((s[i]-'0')^(s[i-1]-'0')) + '0');
        else 
            a.PB(((s[i]-'0')^(a[i-k]-'0')^(s[i-1]-'0')) + '0');
    cout << a << endl;
    return 0;
}