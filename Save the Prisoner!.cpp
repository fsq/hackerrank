#include "stdc++.h"

int main() {
    int t, n, m, s;
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        m += s - 1;
        cout << m % n + 1 << endl;
    }
    return 0;
}