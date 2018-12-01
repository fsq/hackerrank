#include "stdc++.h"

int main() {
    int n; 
    cin >> n;
    REP(i, 1, n) {
        REP(j, 1, n-i) cout << ' ';
        REP(j, n-i+1, n) cout << '#';
        cout << '\n';
    }
    return 0;
}