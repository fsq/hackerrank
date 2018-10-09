#include "stdc++.h"

int n, m;
VI fa, sz;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        cin >> n >> m;

        fa = VI(n+1);
        sz = VI(n+1, 1);
        iota(ALL(fa), 0);
        
        for (int u,v,i=0; i<m; ++i) {
            cin >> u >> v;
            int fx=find(u), fy=find(v);
            if (fx != fy)  {
                fa[fx] = fy;
                sz[fy] += sz[fx];
            }
        }
        multiset<int> st;

        REP(i, 1, n)
            if (fa[i]==i) 
                st.insert(sz[i]);
        
        LL ans = 0;
        int t = 0;
        for (auto it=st.rbegin(); it!=st.rend(); ++it) {
            int n = *it;
            REP(i, 2, n)
                ans += (LL)i * (i-1);
            t += n-1;
            ans += (m-t) * (LL)n*(n-1);

        }

        cout << ans << endl;
    }
    return 0;
}