#include "stdc++.h"

VI all(128);
int target;

bool ok(const string& s, int len) {
    VI now(128);
    FOR(i, SZ(s)) {
        ++now[s[i]];

        if (i>=len) --now[s[i-len]];

        if (i+1>=len && 
            now['C']+target>=all['C'] && 
            now['G']+target>=all['G'] &&
            now['A']+target>=all['A'] && 
            now['T']+target>=all['T'])
                return true;
    }
    return false;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    target = n / 4;

    for (auto c : s) ++all[c];

    int l=0, r=n;
    while (l<r) {
        int mid = (l+r) >> 1;
        if (ok(s, mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}