#include "stdc++.h"

int main() {
    VI h(26);
    FOR(i, 26) cin >> h[i];

    string s;
    cin >> s;
    int mh = 0;
    FOREACH(c, s) mh = max(mh, h[c-'a']);
    cout << mh * s.size() << endl;
    return 0;
}