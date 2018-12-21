#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(n+2);
    REP(i, 1, n) cin >> a[i];
    a[0] = INT_MIN;
    a[n+1] = INT_MAX;

    vector<int> p;
    REP(i, 1, n) 
        if (a[i]>a[i+1]) 
            p.PB(i);

    if (p.size()==0) 
        cout << "yes\n";
    else if (p.size()==1 && a[p[0]]<a[p[0]+2] && a[p[0]-1]<a[p[0]+1]) 
        cout << "yes\nswap " << p[0] << ' ' << p[0]+1 << '\n';
    else if (p.size()==2 && 
             a[p[0]-1]<a[p[1]+1] && a[p[1]+1]<a[p[0]+1] &&
             a[p[1]]<a[p[0]] && a[p[0]]<a[p[1]+2])
        cout << "yes\nswap " << p[0] << ' ' << p[1]+1 << '\n';
    else if (p[0]+p.size()==p.back()+1) {
        reverse(a.begin()+p[0], a.begin()+p[0]+p.size()+1);
        if (is_sorted(ALL(a)))
            cout << "yes\nreverse " << p[0] << ' ' << p.back()+1 << '\n';
        else
            cout << "no\n";
    } else 
        cout << "no\n";
    

    return 0;
    
    
}