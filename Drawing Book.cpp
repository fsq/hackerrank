#include "stdc++.h"

int main() {
    int n, p;
    cin >> n >> p;
    cout << min(p>>1, (n&1) ? (n-p)/2 : (n-p+1)/2) << endl;
    return 0;
}