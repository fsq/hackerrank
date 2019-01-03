#include "stdc++.h"

int main() {
    int t;
    cin >> t;

    LL x;
    while (t--) {
        cin >> x;
        LL y = x;
        y |= y >> 1;
        y |= y >> 2;
        y |= y >> 4;
        y |= y >> 8;
        y |= y >> 16;
        y |= y >> 32;
        y ^= y >> 1;
        cout << (y<<1)-x-1 << endl;
    }
    return 0;
}