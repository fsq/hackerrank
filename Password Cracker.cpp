#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> a(n);
        FOR(i, n) cin >> a[i];

        string s;
        cin >> s;

        VI f(s.size(), -1);
        FORI(i, s)
            FORI(j, a)
                if (i+1>=SZ(a[j]) && (i+1==SZ(a[j]) || f[i-SZ(a[j])]!=-1) &&
                     equal(ALL(a[j]), s.begin()+i-SZ(a[j])+1)) {
                    f[i] = j;
                    break;
                }
        if (f.back()!=-1) {
            VI d;
            for (int i=SZ(s)-1; i>=0; i-=SZ(a[f[i]])) 
                d.PB(f[i]);
            PER(i, SZ(d)-1, 1) cout << a[d[i]] << ' ';
            cout << a[d[0]] << endl;
        } else 
            cout << "WRONG PASSWORD\n";
    }
    return 0;
}