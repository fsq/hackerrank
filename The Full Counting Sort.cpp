#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<vector<string>> buckets(101);
    string s;
    int x;
    for (int i=0; i<n; ++i) {
        cin >> x >> s;
        buckets[x].PB(i<n/2 ? "-" : s);
    }
    for (int i=0; i<100; ++i)
        if (buckets[i].size()) 
            for (auto& s : buckets[i]) 
                cout << s << ' ';
    return 0;
}