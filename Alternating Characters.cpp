#include "stdc++.h"

int main() {
    int q;
    cin >> q;
    string s;
    while (q--) {
        cin >> s;
        int ans = 0;
        for (int j,i=0; i<s.size(); i=j) {
            ++ans;
            for (j=i+1; j<s.size() && s[j]==s[i]; ++j);
        }
        cout << s.size() - ans << endl;
    }
    return 0;
}