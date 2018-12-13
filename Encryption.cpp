#include "stdc++.h"

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int lo=sqrt(n), up=ceil(sqrt(n));

    int x1=lo, y1=(n+x1-1) / x1;
    int x2=lo+1, y2=(n+x2-1) / x2;

    if (y1>up || x2*y2<x1*y1) {
        swap(x1, x2);
        swap(y1, y2);
    }

    for (int i=0; i<y1; ++i) {
        for (int j=i; j<n; j+=y1)
            cout << s[j];
        cout << ' ';
    }
    cout << endl;
    return 0;
}