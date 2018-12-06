#include "stdc++.h"

int main() {
    int n, k, b, s=0;
    cin >> n >> k;

    VI a(n);
    FOR(i, n) {
        cin >> a[i];
        s += a[i];
    }

    cin >> b;

    if (b==(s-a[k])/2) 
        cout << "Bon Appetit\n";
    else 
        cout << b - (s-a[k])/2 << endl;


    return 0;
}