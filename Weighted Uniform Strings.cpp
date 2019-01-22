#include "stdc++.h"

int main() {
    VI len(26);
    string s;
    cin >> s;
    for (int j,i=0; i<s.size(); i=j) {
        for (j=i; j<s.size() && s[j]==s[i]; ++j);
        len[s[i]-'a'] = max(len[s[i]-'a'], j-i);
    }

    int t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        bool ok = false;
        FORI(i, len) 
            if (x%(i+1)==0 && x/(i+1)<=len[i]) {
                ok = true;
                break;
            }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}