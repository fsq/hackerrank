#include "stdc++.h"

int main() {
    string s;
    int n;
    cin >> s >> n;

    VI a;
    a.PB(0);
    FORI(i, s)
        a.PB(a.back() + (a[i]=='a'));

    LL ans = 0;
    LL rep = n/SZ(s), rem = n % SZ(s);
    ans = rep*a.back() + a[rem];
    cout << ans << endl;
    return 0;
}