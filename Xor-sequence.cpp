#include "stdc++.h"

LL f(LL x) {
    if (x<=0) return 0;
    LL n = x/8, m = x%8;
    if (m==2 || m==3)
        return 2;
    else if (m==6 || m==7)
        return 0;
    else if (m<=1) 
        return x;
    else 
        return x + 2;
}

int main() {
    int t;
    cin >> t;
    LL l, r;
    while (t--) {
        cin >> l >> r;
        cout << (f(r) ^ f(l-1)) << endl;
    }
    
    return 0;
}