#include "stdc++.h"

int main() {
    VI a(9);
    FOR(i, 9) cin >> a[i];

    VI p(9);
    int ans = INT_MAX, sum;
    iota(ALL(p), 1);
    do {
        FOR(i, 3)
            if (p[i*3]+p[i*3+1]+p[i*3+2] != 15)
                goto next;
        FOR(i, 3)
            if (p[i]+p[i+3]+p[i+6] != 15)
                goto next;
        if (p[0]+p[4]+p[8]!=15 || p[2]+p[4]+p[6]!=15)
            goto next;

        sum = 0;
        FOR(i, 9) sum += abs(p[i] - a[i]);
        ans = min(ans, sum);

        next:;

    } while (next_permutation(ALL(p)));

    cout << ans << endl;
    return 0;
}