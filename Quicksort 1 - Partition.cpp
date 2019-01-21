#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(n);
    FORI(i, a) cin >> a[i];

    int i=0,j=0,k=n-1, x=a.front();
    while (j<=k)    
        if (a[j]==x)
            ++j;
        else if (a[j]<x)
            swap(a[i++], a[j++]);
        else 
            swap(a[k--], a[j]);
    FOREACH(x, a) cout << x << ' ';
    cout << endl;
    return 0;
}