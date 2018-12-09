#include "stdc++.h"

int main() {
    int q;
    cin >> q;
    for (int x,y,z,i=0; i<q; ++i) {
        cin >> x >> y >> z;
        int d1 = abs(x-z), d2 = abs(y-z);
        if (d1==d2)
            cout << "Mouse C\n";
        else if (d1 < d2) 
            cout << "Cat A\n";
        else 
            cout << "Cat B\n";
    }
    return 0;
}