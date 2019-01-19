#include "stdc++.h"

int main() {
    long double t;
    cin >> t;
    int n = ceil(log10(t/3+1) / log10(2));
    t -= 3*(pow((long double)2,n-1)-1);
    cout << fixed << (LL)(3*pow(2, n-1)-t+1) << endl;
    return 0;
}