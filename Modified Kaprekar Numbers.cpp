#include "stdc++.h"

int main() {
    int p, q, cnt=0;
    cin >> p >> q;
    REP(x, p, q) {
        LL n = (LL)x * x;
        string s = to_string(n);
        int m = to_string(x).size();
        LL b = stoll(s.substr(SZ(s)-m)), a = SZ(s)==m ? 0 : stoll(s.substr(0, SZ(s)-m));
        if (a+b==x) {
            cout << x << ' ';
            ++cnt;
        }
    }
    if (cnt==0)
        cout << "INVALID RANGE\n";
    return 0;
}