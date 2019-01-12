#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;

    int mx = 0;
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        mx = max(mx, x);
    }

    cout << max(0, k-mx) << endl;
    return 0;
}