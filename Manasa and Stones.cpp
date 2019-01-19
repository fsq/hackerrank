#include "stdc++.h"

int main() {
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if (a>b) swap(a, b);
        --n;
        if (a==b)
            cout << n*a << endl;
        else {
            REP(i, 0, n) 
                cout << a*(n-i)+b*i << ' ';
            cout << endl;
        }
    }
    return 0;
}