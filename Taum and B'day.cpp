#include "stdc++.h"

int main() {
    int t;
    LL b,w,bc,wc,z,x,y;
    cin >> t;
    while (t--) {
        cin >> b >> w >> bc >> wc >> z;
        x = min(bc, wc+z);
        y = min(wc, bc+z);
        cout << x*b+y*w << endl;
    }
    return 0;
}