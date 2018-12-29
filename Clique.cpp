#include "stdc++.h"


// Turán graph
int main() {
    int t;
    LL n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        LL l=1, r=n+1;
        while (l<r) {
            LL mid = (l+r) >> 1;
            double b = (n*n-(n%mid)*pow(ceil((double)n/mid),2) - (mid-(n%mid))*pow(n/mid,2)) / 2;
            if (m<=b) 
                r = mid;
            else 
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}