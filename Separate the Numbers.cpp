#include "stdc++.h"

bool dfs(const string& s, int i, LL pre) {
    if (i==SZ(s)) return true;
    string target = to_string(pre + 1);
    if (equal(ALL(target), s.begin()+i))
        return dfs(s, i+target.size(), pre+1);
    else 
        return false;
}

int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        if (s[0]=='0') 
            cout << "NO\n";
        else {
            bool ok = false;
            REP(i, 1, s.size()/2) {
                LL first = stoll(s.substr(0, i));
                if (dfs(s, i, first)) {
                    ok = true;
                    cout << "YES" << ' ' << first << endl;
                    break;
                }
            }
            if (!ok) cout << "NO\n";
        }
    }
    return 0;
}