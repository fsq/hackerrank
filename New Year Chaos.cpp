#include "stdc++.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, x;
        list<int> a;
        REP(i, 1, n) a.push_back(i);
        auto it = a.begin();

        bool ok = true;
        REP(i, 1, n) {
            cin >> x;
            if (!ok) continue;
            if (*it==x) {
                ++it;
                continue;
            } else if (next(it)!=a.end())
                if (*next(it)==x) {
                    a.erase(next(it));
                    it = next(a.insert(it, x));
                    ++ans;
                    continue;
                } else if (next(it,2)!=a.end() && *next(it,2)==x) {
                    a.erase(next(it,2));
                    it = next(a.insert(it, x));
                    ans += 2;
                    continue;
                } else {}
            else {}
            ok = false;
        } 
        cout << (ok ? to_string(ans) : "Too chaotic") << endl;
    }
    return 0;
}