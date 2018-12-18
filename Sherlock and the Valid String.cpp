#include "stdc++.h"

int main() {
    string s;
    cin >> s;

    VI a(26);
    FOREACH(c, s)  ++a[c-'a'];


    unordered_map<int, int> map;
    for (auto x : a)
        if (x>0) ++map[x];

    if (map.size()==1)
        cout << "YES\n";
    else if (map.size()==2) {
        PII x=*map.begin(), y=*next(map.begin());
        if (x.first>y.first) swap(x, y);

        if (y.first==x.first+1 && y.second==1 || x.second==1)
            cout << "YES\n";
        else
            cout << "NO\n";
    } else 
        cout << "NO\n";

    return 0;
}