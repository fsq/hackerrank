#include "stdc++.h"

vector<vector<PII>> e;
VI son, fa;
VLL ans;
int n;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int count_son(int x, int pre=-1) {
    int cnt = 1;
    FOREACH(&eg, e[x])
        if (eg.F != pre) {
            LL cs = count_son(eg.F, x);
            ans[eg.S] = cs * (n-cs);
            cnt += cs;
        }
    return cnt;
}

void read() {
    int m;
    cin >> n >> m;

    ans.resize(m);
    e.resize(n+1);
    son.resize(n+1);
    fa.resize(n+1);
    iota(ALL(fa), 0);

    VVI edges(m, VI(3));
    FOR(i, m) cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    sort(ALL(edges));

    for (auto& eg : edges) 
        if (int fx=find(eg[1]), fy=find(eg[2]); fx != fy) {
            fa[fx] = fy;
            e[eg[1]].PB({eg[2], eg[0]});
            e[eg[2]].PB({eg[1], eg[0]});
        }
}

int main() {
    read();
    count_son(1);

    FORI(i, ans)
        if (ans[i] > 1) {
            if (i+1==SZ(ans)) 
                ans.PB(ans[i]>>1);
            else 
                ans[i+1] += ans[i] >> 1;
            ans[i] &= 1;
        }
    while (ans.back()==0) ans.pop_back();
    reverse(ALL(ans));
    FOREACH(x, ans) cout << x;
    cout << endl;

    return 0;
}