#include "stdc++.h"

bool isPan(string s) {
    for (int i=0,j=s.size()-1; i<j; ++i,--j)
        if (s[i]!=s[j]) 
            return false;
    return true;
}

int main() {
    int q;
    string s;
    cin >> q;
    while (q--) {
        cin >> s;
        if (isPan(s))
            cout << "-1\n";
        else 
            for (int i=0, j=s.size()-1; i<j; ++i, --j)
                if (s[i]!=s[j]) {
                    if (isPan(s.substr(i+1, j-i)))
                        cout << i << endl;
                    else 
                        cout << j << endl;
                    break;
                }
    }
    return 0;
}