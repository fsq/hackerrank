#include "stdc++.h"

int main() {
    int d, a=5, acc=0;
    cin >> d;

    REP(i, 1, d) {
        acc += a / 2;
        a = a / 2 * 3;
    }
    cout << acc << endl;

    return 0;
}