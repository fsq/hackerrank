#include "stdc++.h"

int main() {
    VI a(3), b(3);
    REP(i, 0, 2) cin >> a[i];
    REP(i, 0, 2) cin >> b[i];

    int x=0, y=0;
    REP(i, 0, 2)
        if (a[i]>b[i]) ++x;
            else if (a[i]<b[i]) ++y;
    cout << x << ' ' << y << endl;
    return 0;
}