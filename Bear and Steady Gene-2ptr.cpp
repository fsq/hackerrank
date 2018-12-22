#include "stdc++.h"

int main() {
    int n, target;
    string s;
    cin >> n >> s;

    target = n / 4;
    VI all(128), now(128);
    for (auto c : s) ++all[c];
    int ans = n;

    for (int l=0,r=0; r<n; ++r) {
        ++now[s[r]];
        while (now[s[l]] && now[s[l]]+target>all[s[l]]) 
            --now[s[l++]];
        if (now['C']+target>=all['C'] && 
            now['G']+target>=all['G'] &&
            now['A']+target>=all['A'] && 
            now['T']+target>=all['T'])
            ans = min(ans, r-l+1);
    }

    cout << ans << endl;

    return 0;
}