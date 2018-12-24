#include "stdc++.h"

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, map<int,int>> rows;

    for (int r,c1,c2,i=0; i<k; ++i) {
        cin >> r >> c1 >> c2;
        ++rows[r][c1];
        --rows[r][c2+1];
    }

    LL ans = (LL)n * m;
    FOREACH(kv, rows) {
        auto& row = kv.second;
        for (auto it=row.begin(); it!=row.end(); ++it) {
            int lf = it->first, tot = it->second;
            while (tot) 
                tot += (++it)->second;
            
            ans -= it->first - lf;
        }
    }

    cout << ans << endl;
    return 0;
}