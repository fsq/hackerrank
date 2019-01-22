#include "stdc++.h"

int main() {
    int q;
    cin >> q;
    string s;
    while (q--) {
        cin >> s;
        bool ok = true;
        for (int i=0, j=SZ(s)-1; i+1<j; ++i, --j)
            if (abs(s[i+1]-s[i]) != abs(s[j]-s[j-1])) {
                ok = false;
                break;
            }
        cout << (ok ? "" : "Not ") << "Funny\n";

    }
    return 0;
}