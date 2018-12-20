#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a;
    b = a;

    int change = 0;
    for (int i=0, j=n-1; i<j; ++i, --j) 
        if (a[i]!=a[j]) {
            a[i] = a[j] = max(a[i], a[j]);
            ++change;
        }

    if (change>k) 
        cout << "-1\n";
    else {
        for (int i=0, j=n-1; i<j && change<k; ++i, --j)
            if (a[i]!='9') {
                int tmp = change;
                change += 2;
                if (a[i]!=b[i]) --change;
                if (a[j]!=b[j]) --change;
                if (change<=k) 
                    a[i] = a[j] = '9';
                else {
                    change = tmp;
                    break;
                }
            }   
        if ((n&1) && change<k)
            a[n/2] = '9';
        cout << a << '\n';
    }

    return 0;
}