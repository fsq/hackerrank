#include "stdc++.h"

int main() {
    int n;
    vector<int> buckets(20001);
    cin >> n;
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        ++buckets[x+10000];
    }
    int i = -1;
    for (int cnt=0; cnt<=n/2; cnt+=buckets[++i]);
    cout << i-10000 << endl;

    return 0;
}