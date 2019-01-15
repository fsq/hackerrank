#include "stdc++.h"

int main() {
    string s, t;
    int k;
    cin >> s >> t;
    cin >> k;
    int i, n=s.size(), m=t.size();
    for (i=0; i<min(n,m); ++i) if (s[i]!=t[i]) break;

    int cnt = n-i+m-i;
    if (n+m<=k || cnt==0)
        cout << "Yes\n";
    else if (i==0)
        cout << (cnt<=k ? "Yes" : "No") << endl;
    else 
        cout << (cnt<=k && (k-cnt)%2==0 ? "Yes" : "No") << endl;
    return 0;
}