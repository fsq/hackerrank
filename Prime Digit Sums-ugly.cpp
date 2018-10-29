#include "stdc++.h"

int validTail[100000];
int ans[400001];
unordered_map<int, int> pre, f;
int prime[60];

const int M = 1e9 + 7;

bool isPrime(int x) {
    for (int i=2, m=sqrt(x); i<=m; ++i)
        if (x % i==0)
            return false;
    return true;
}

int sumDig(int x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

bool isValidTail5(int x) {
    string s = to_string(x);
    while (s.size()<5) s = '0' + s;
    REP(l, 3, 5)
        REP(i, 0, 5-l)
            if (!prime[sumDig(stoi(s.substr(i, l)))]) 
                return false;
    return true;
}

void preprocess() {
    REP(t, 2, 45)
        if (isPrime(t))
            prime[t] = true;

    ans[1] = 9;
    ans[2] = 90;
    
    REP(x, 100, 999)
        if (prime[sumDig(x)])
            ++ans[3];
    
    REP(x, 1000, 9999)
        if (prime[sumDig(x)] && prime[sumDig(x/10)] && prime[sumDig(x%1000)])
            ++ans[4];

    REP(x, 2, 99999) 
        if (isValidTail5(x)) {
            if (x>=10000) {
                ++ans[5];
                pre[x] = 1;
            }
            validTail[x] = true;
        }
}

int main() {
    ios::sync_with_stdio(false);
    int q, n = 0;
    cin >> q;

    VI qs(q);
    FOR(i, q) {
        cin >> qs[i];
        ans[qs[i]] = 0;
        n = max(n, qs[i]);
    }

    preprocess();

    REP(i, 6, min(100, n)) {
        f.clear();
        for (auto& kv : pre) {
            int tail = kv.first, cnt = kv.second;
            REP(last, 0, 9) {
                int now = (tail*10+last) % 100000;
                if (validTail[now]) {
                    f[now] = (f[now]+cnt) % M;
                    ans[i] = (ans[i]+cnt) % M;
                }
            }
        }
        f.swap(pre);
    }

    if (n>100) {
        VI valid;
        for (auto& kv : pre) valid.PB(kv.first);
        int m = valid.size();
        VVI e(m);
        FOR(i, m)
            FOR(j, m)
                if (valid[i]%10000==valid[j]/10)
                    e[i].PB(j);
        
        VI prev(m), nxt(m);
        FOR(i, m)
            prev[i] = pre[valid[i]];
        REP(i, 101, n) {
            FILL0(nxt);
            FOR(a, m)
                FOREACH(b, e[a]) {
                    nxt[b] = (nxt[b]+prev[a]) % M;
                    ans[i] = (ans[i]+prev[a]) % M;
                }
            prev.swap(nxt);
        }
    }

    for (auto q : qs)
        cout << ans[q] << '\n';

    return 0;
}