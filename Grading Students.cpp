#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        int h = (x+4) / 5 * 5;
        h = h-x<3 ? h : x;

        cout << (h<38 ? x : h) << endl;
    }
    return 0;
}