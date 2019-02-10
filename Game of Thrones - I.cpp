#include "stdc++.h"

int main() {
    string s;
    cin >> s;
    VI cnt(26);
    FOREACH(c, s) ++cnt[c-'a'];
    int odd = count_if(ALL(cnt), [](int x){ return x & 1; });
    cout << (odd<=1 ? "YES" : "NO") << endl;
    return 0;
}