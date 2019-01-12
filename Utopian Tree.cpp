#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ((1ll << n/2+1)-1)*(1ll+(n&1)) << endl;
    }
    return 0;
}