#include "stdc++.h"

VI parse(const string& s, int n) {
    VI a(4*n);
    FORI(i, s) {
        int x = stoi(string(1,s[i]), nullptr, 16);
        PER(j, 3, 0) a[(n-SZ(s)+i)*4+(3-j)] = x>>j & 1;
    }
    return a;
}

void print(const VI& a) {
    bool printed = false;
    for (int i=0; i<a.size(); i+=4) {
        int x = (a[i]<<3) + (a[i+1]<<2) + (a[i+2]<<1) + a[i+3];
        if (!(!printed && x==0)) {
            cout << hex << uppercase << x;
            printed = true;
        }
    }
    if (!printed) cout << 0;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        string sa, sb, sc;
        cin >> sa >> sb >> sc;

        int n = max(max(SZ(sa), SZ(sb)), SZ(sc));

        auto a = parse(sa, n), b = parse(sb, n), c = parse(sc, n);
        FORI(i, a) {
            if ((a[i]|b[i]) != c[i]) 
                if (c[i]==0) {
                    if (a[i]==1) --k, a[i] = 0;
                    if (b[i]==1) --k, b[i] = 0;
                } else 
                    --k, b[i] = 1;
            else {}
            if (k<0) break;
        }

        if (k>0)
            FORI(i, a) 
                if (c[i]==1) {
                    if (a[i]==1 && b[i]==1)
                        --k, a[i] = 0;
                    else if (k>=2 && a[i]==1) {
                        k-=2, a[i] = 0, b[i] = 1;
                    }
                    if (k==0) break;
                }


        if (k<0)
            cout << "-1" << endl;
        else {
            print(a); 
            print(b); 
        }
    }
    return 0;
}