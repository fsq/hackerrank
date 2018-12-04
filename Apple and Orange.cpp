 #include "stdc++.h"

int main() {
    int s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;
    int x=0, y=0;
    for (int p,i=0; i<m; ++i) {
        cin >> p;
        if (a+p>=s && a+p<=t) ++x;
    }
    for (int p,i=0; i<n; ++i) {
        cin >> p;
        if (b+p>=s && b+p<=t) ++y;
    }
    cout << x << '\n' << y << endl;
    return 0;
}