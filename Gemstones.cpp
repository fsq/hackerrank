#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI show(26), cnt(26);

    string s;
    FOR(i, n) {
        FILL(show, 0);
        cin >> s;
        FOREACH(c, s)
            if (!show[c-'a']) {
                show[c-'a'] = true;
                ++cnt[c-'a'];
            }
    }
    cout << count_if(ALL(cnt), [=](int x) { return x==n; }) << endl;
    return 0;
}