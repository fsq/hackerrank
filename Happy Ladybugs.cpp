#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    string s;
    while (t--) {
        cin >> n >> s;
        VI cnt(26);
        int empty = 0;
        FOREACH(c, s)
            if (c!='_')
                ++cnt[c-'A'];
            else 
                ++empty;
        bool sorted = true;
        FOR(i, n) 
            if (!((i>0 && s[i-1]==s[i]) || (i+1<n && s[i+1]==s[i]))) {
                sorted = false;
                break;
            }
        
        if (sorted || (count(ALL(cnt),1)==0 && empty))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}