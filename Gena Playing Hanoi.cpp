#include "stdc++.h"
int n;

int encode(const VVI& a) {
    int s = 0;
    FOR(i, 4)
        FOREACH(x, a[i]) 
            s |= i << (x<<1);
    return s;
}

VVI decode(int s) {
    VVI a(4);
    PER(i, n-1, 0) 
        a[(s>>(i<<1)) & 3].PB(i);
    return a;
}

int main() {
    cin >> n;

    VVI init(4);
    for (int x,i=0; i<n; ++i) {
        cin >> x;
        init[--x].PB(i);
    }

    FOR(i, 4) reverse(ALL(init[i]));

    int ori = encode(init), target = 0;
    queue<int> q;
    q.push(ori);
    VI vis(1<<(2*n), -1);
    vis[ori] = 0;
    
    int ans = -1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        VVI tw = decode(now);
        FOR(i, 4) FOR(j, 4)
            if (i!=j && tw[i].size() && (tw[j].empty() || tw[i].back()<tw[j].back())) {
                auto nxt = tw;
                nxt[j].PB(nxt[i].back());
                nxt[i].pop_back();
                auto state = encode(nxt);
                if (vis[state]==-1) {
                    vis[state] = vis[now] + 1;
                    if (state==target) goto final;
                    q.push(state);
                }
            }
    }

    final:
    cout << vis[0] << endl;

    return 0;
}