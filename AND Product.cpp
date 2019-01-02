#include "stdc++.h"

int main() {
    int n;
    LL a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;

        LL s = 0;
        FOR(i, 32)
            if ((a>>i) & 1) {
                LL x = ((a>>i)+1) << i;
                if (x>b)
                    s |= 1LL << i;
            }
        cout << s << endl;
    }
    return 0;
}