#include "stdc++.h"

const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), ' ');

    VVI c(n+1, VI(26));
    REP(i, 1, n) {
        c[i] = c[i-1];
        ++c[i][s[i]-'a'];
    }

    LL ans = 0;
    VVI tail(26, VI(26));
    VI cnt(26);
    PER(i, n, 1) {
        REP(a, 'a', 'z') 
            ans = (ans + (LL)c[i-1][a-'a']*tail[s[i]-'a'][a-'a']) % M;
        REP(a, 'a', 'z')
            tail[s[i]-'a'][a-'a'] = (tail[s[i]-'a'][a-'a']+cnt[a-'a']) % M;
        ++cnt[s[i]-'a'];
    }

    cout << ans << endl;
        


    return 0;
}