#include "stdc++.h"

int main() {
    int n, k, x, cnt=0;
    cin >> n >> k;
    FOR(i, n) {
        cin >> x;
        if (x < k) ++cnt;
    }
    cout << cnt << endl;
    
    return 0;
}