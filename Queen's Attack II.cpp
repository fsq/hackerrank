#include "stdc++.h"

VI dx={1,1,1,0,-1,-1,-1,0};
VI dy={-1,0,1,1,1,0,-1,-1};

int main() {
    int n, k, sx, sy;
    cin >> n >> k;
    cin >> sx >> sy;

    set<pair<int,int>> st;
    for (int x,y,i=0; i<k; ++i) {
        cin >> x >> y;
        st.insert({x, y});
    }

    int ans = 0;
    FOR(dir, 8) {
        int x=sx, y=sy;
        while (x>=1 && x<=n && y>=1 && y<=n && !st.count({x, y})) {
            ++ans;
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout << ans - 8 << endl;

    return 0;
}