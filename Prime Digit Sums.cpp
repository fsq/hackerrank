#include "stdc++.h"

int ans[400007], prime[60], pos[10000];
VI tail, pre, f;
VVI e;
queue<int> q;
const int M = 1e9 + 7;

void getPrimes() {
    MEMSET(prime, 0);
    REP(x, 2, 45) {
        bool ok = true;
        for (int m=sqrt(x), i=2; i<=m; ++i)
            if (x % i==0) {
                ok = false;
                break;
            }
        prime[x] = ok;
    }
}


bool valid4(int x) {
    int f3 = x/1000 + x/100%10 + x/10%10;
    int s4 = f3 + x%10;
    int t3 = x/100%10 + x/10%10 + x%10;
    return prime[f3] && prime[s4] && prime[t3];
}

bool valid5(int x) {
    if (!(valid4(x/10) && valid4(x%10000))) return false;
    int s = x/10000 + x/1000%10 + x/100%10 + x/10%10 + x%10;
    return prime[s];
}

void preprocess() {
    MEMSET(ans, 0);

    getPrimes();

    ans[1] = 9;
    ans[2] = 90;

    REP(x, 100, 999)
        if (prime[x/100+x/10%10+x%10])
            ++ans[3];

    REP(x, 0, 9999) 
        if (valid4(x)) {
            pos[x] = tail.size();
            tail.PB(x);
            pre.PB(0);
            if (x>=1000) {
                ++ans[4];
                q.push(pos[x]);
                pre[pos[x]] = 1;
            }
        }
    f.resize(pre.size());
}

void build() {
    e.resize(tail.size());
    FOR(i, tail.size()) {
        int now = tail[i];
        REP(last, 0, 9) {
            int nxt = now*10 + last;
            if (valid5(nxt)) 
                e[i].PB(pos[nxt%10000]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int nq, n=0;
    cin >> nq;
    VI query(nq);
    FOR(i, nq) {
        cin >> query[i];
        n = max(n, query[i]);
    }

    preprocess();
    build();

    REP(i, 5, n) {
        int sz = q.size();
        while (sz--) {
            int now = q.front(); q.pop();
            for (auto nxt : e[now]) {
                if (!f[nxt])
                    q.push(nxt);
                f[nxt] = (f[nxt] + pre[now]) % M;
                ans[i] = (ans[i] + pre[now]) % M;
            }
            pre[now] = 0;
        }
        pre.swap(f);
    }

    for (auto qr : query)
        cout << ans[qr] << '\n';


    return 0;
}