#include "stdc++.h"

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    VI f(n+1), pre(n+1);

    FOR(i, n) {
        FOR(j, n) 
            if (a[i]==b[j])
                f[j] = (j==0 ? 0 : pre[j-1]) + 1;
            else
                f[j] = max(pre[j], (j==0 ? 0 : f[j-1]));
        f.swap(pre);
    }
    cout << pre[n-1] << endl;
    return 0;
}