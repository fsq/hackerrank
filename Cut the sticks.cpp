#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(1001);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++a[x];
    }

    FOREACH(x, a)
        if (x) {
            cout << n << endl;
            n -= x;
        }
    return 0;
}