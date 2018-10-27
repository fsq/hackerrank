#include "stdc++.h"

int main() {

    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        VI pre(m+1), f(m+1);
        pre[0] = true;
        bool hasUpper = false;
        REP(i, 1, n) {
            hasUpper |= isupper(a[i-1]);
            f[0] = !hasUpper;
            REP(j, 1, m)
                if (isupper(a[i-1]))
                    f[j] = a[i-1]==b[j-1] && pre[j-1];
                else 
                    f[j] = (toupper(a[i-1])==b[j-1] && pre[j-1]) || pre[j];
            pre.swap(f);
        }

        cout << (pre[m] ? "YES" : "NO") << endl;
    }
    return 0;
}