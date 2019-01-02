#include "stdc++.h"

int count(unsigned long long x) {
    int s = 0;
    while (x) {
        s += x & 1;
        x >>= 1;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    unsigned long long n;
    while (t--) {
        cin >> n;
        int b = count(n);
        FOR(i, 64)
            if ((n>>i) & 1) {
                int cnt = b-1 + i;
                cout << ((cnt&1) ? "Louise" : "Richard")<< endl;
                break;
            }
    }
    return 0;
}