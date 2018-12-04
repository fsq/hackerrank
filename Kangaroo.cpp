#include "stdc++.h"

int main() {
    int x1, x2, v1, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if (v1<=v2)
        cout << "NO\n";
    else {
        int m = x2 - x1, n = v1 - v2;
        cout << (m%n==0 ? "YES" : "NO") << endl;
    }
    return 0;
}