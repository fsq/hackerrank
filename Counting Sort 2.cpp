#include "stdc++.h"

int main() {
    int n, x;
    cin >> n;
    VI cnt(100);
    FOR(i, n) {
        cin >> x;
        ++cnt[x];
    }
    FORI(i, cnt) 
        FOR(j, cnt[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}