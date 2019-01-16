#include "stdc++.h"
#include <bitset>

using BS = bitset<500>;

int main() {
    int n;
    string s;
    cin >> n;
    vector<BS> st(n);

    FOR(i, n) {
        cin >> s;
        FORI(j, s)
            if (s[j]=='1')
                st[i][j] = 1;
    }

    int mx=0, cnt=0;
    FOR(i, n)
        REP(j, i+1, n-1) {
            int c = (st[i] | st[j]).count();
            if (c > mx) {
                mx = c;
                cnt = 1;
            } else if (c==mx)
                ++cnt;
        }
    cout << mx << '\n' << cnt << endl;



    return 0;
}