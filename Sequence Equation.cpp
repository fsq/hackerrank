#include "stdc++.h"

int main() {
    int n, x;
    cin >> n;
    VI pos(n+1);
    REP(i, 1, n) {
        cin >> x;
        pos[x] = i;
    }

    REP(i, 1, n) 
        cout << pos[pos[i]] << endl;
    
    return 0;
}