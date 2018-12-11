#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int q, n, x;
    cin >> q;

    while (q--) {
        cin >> n;
        VI row(n), col(n);

        FOR(i, n) FOR(j, n) {
            cin >> x;
            row[i] += x;
            col[j] += x;
        }

        sort(ALL(row)); 
        sort(ALL(col));

        bool pos = true;
        FOR(i, n)
            if (col[i]>row[i]) {
                pos = false;
                break;
            }

        cout << (pos ? "Possible" : "Impossible") << endl;
    }
    return 0;
}