#include "stdc++.h"

int main() {
    int t, n, m, src;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<unordered_set<int>> e(n+1);
        for (int x,y,i=0; i<m; ++i) {
            cin >> x >> y;
            e[x].insert(y);
            e[y].insert(x);
        }
        cin >> src;
        VI d(n+1, INT_MAX);
        d[src] = 0;
        queue<int> q;
        q.push(src);
        VI cand(n);
        iota(ALL(cand), 1);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int i=0; i<cand.size(); )
                if (d[cand[i]]==INT_MAX && !e[x].count(cand[i])) {
                    d[cand[i]] = d[x] + 1;
                    q.push(cand[i]);
                    swap(cand[i], cand.back());
                    cand.pop_back();
                } else 
                    ++i;
        }
        REP(i, 1, n) 
            if (i != src)
                cout << d[i] << ' ';
        cout << endl;
    }
    return 0;
}