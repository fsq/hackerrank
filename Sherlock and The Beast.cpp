#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    end:    
    while (t--) {
        cin >> n;
        for (int i=n/3; i>=0; --i)
            if ((n-3*i) % 5 == 0) {
                cout << string(i*3, '5') << string(n-3*i, '3') << endl;
                goto end;
            }
        cout << -1 << endl;
    }
    return 0;
}