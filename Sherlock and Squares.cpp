#include "stdc++.h"

int main() {
    int q;
    cin >> q;
    LL a, b;
    while (q--) {
        cin >> a >> b;
        int x=ceil(sqrt(a)), y=sqrt(b);
        cout << y-x+1 << endl;
    }
    return 0;
}