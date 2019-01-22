#include "stdc++.h"

int main() {
    int n, x;
    cin >> n;
    VI cnt(100);
    FOR(i, n) {
        cin >> x;
        ++cnt[x];
    }
    FOREACH(x, cnt) 
        cout << x << ' ';
    cout << endl;
    return 0;
}