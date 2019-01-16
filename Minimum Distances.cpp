#include "stdc++.h"

int main() {
    int n, x;
    cin >> n;

    VI p(100001, -1);
    int mind = INT_MAX;
    FOR(i, n) {
        cin >> x;
        if (p[x]!=-1)
            mind = min(mind, i-p[x]);
        p[x] = i;
    }
    cout << (mind==INT_MAX ? -1 : mind) << endl;

    return 0;
}