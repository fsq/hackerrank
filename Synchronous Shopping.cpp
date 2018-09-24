#include "stdc++.h"

int n, m, k;
VI fish;
vector<vector<PII>> e;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    fish.resize(n+1);
    e.resize(n+1);

    for (int t,i=1; i<=n; ++i) {
        cin >> t;
        for (int x,j=0; j<t; ++j) {
            cin >> x;
            fish[i] |= 1<<x;
        }
    }

    for (int x,y,z,i=0; i<m; ++i) {
        cin >> x >> y >> z;
        e[x].PB({y, z});
        e[y].PB({x, z});
    }

    VVI dis(n+1, VI(1<<(k+1), INT_MAX)); // n, fish
    VVI vis(n+1, VI(1<<(k+1)));
    priority_queue<VI, VVI, std::greater<VI>> q; // dis, n, fish
    q.push({0, 1, fish[1]});
    dis[1][fish[1]] = 0;

    while (!q.empty()) {
        while (!q.empty() && vis[q.top()[1]][q.top()[2]]) 
            q.pop();

        if (!q.empty()) {
            int d = q.top()[0], x = q.top()[1], f = q.top()[2];
            vis[x][f] = 1;
            q.pop();
            for (auto& ed : e[x]) {
                int y = ed.first, z = ed.second;
                int nf = f | fish[y];
                if (dis[y][nf] > d + z) {
                    dis[y][nf] = d + z;
                    q.push({d+z, y, nf});
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int fst=0; fst<(1<<(k+1)); ++fst) 
        for (int snd=0; snd<(1<<(k+1)); ++snd)
            if ( (fst|snd) == (1<<(k+1))-2) 
                ans = min(ans, max(dis[n][fst],dis[n][snd]));
            
    cout << ans << endl;
    return 0;
}
