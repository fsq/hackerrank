#include "stdc++.h"

const int N = 37;
int n, m;
int a[N][N];
int c[N];

int val[1<<20], f[1<<20], cnt[1<<20];

bool ok(const vector<int>& d) {
    for (auto u : d)
        for (auto v : d)
            if (u!=v && a[u][v]) 
                return false;
    return true;
}

void dfs(const int msk, const int i, const int now, const int k) {
    if (i==k) {
        if (val[now] > f[msk]) {
            f[msk] = val[now];
            cnt[msk] = 1;
        } else if (val[now]==f[msk])
            ++cnt[msk];
    } else {
        dfs(msk, i+1, now, k);
        if (msk>>i & 1)
            dfs(msk, i+1, now + (1<<i), k);
    }
}

int main() {
    ios::sync_with_stdio(false);

    MEMSET(a, 0);
    MEMSET(val, 0);
    MEMSET(cnt, 0);
    MEMSET(c, 0);
    MEMSET(f, 0);

    cin >> n >> m;
    FOR(i, n) cin >> c[i];
    for (int u,v,i=0; i<m; ++i) {
        cin >> u >> v;
        --u, --v;
        a[u][v] = a[v][u] = true;
    }

    int k = n / 2;

    for (int sum, i=0; i<(1<<k); ++i) {
        vector<int> d;
        sum = 0;
        for (int j=0; j<k; ++j) 
            if ((i>>j) & 1) {
                sum += c[j];
                d.PB(j);
            }
        val[i] = ok(d) ? sum : -1;
    }

    for (int i=0; i<(1<<k); ++i) dfs(i, 0, 0, k);

    int maxSum = -1;
    LL ways = 0;

    for (int sum, i=0; i<(1<<(n-k)); ++i) {
        vector<int> d;
        sum = 0;
        for (int j=0; j<n-k; ++j)
            if ((i>>j) & 1) {
                sum += c[j+k];
                d.PB(j+k);
            }
        if (ok(d)) {
            int msk = (1<<k) - 1;
            for (auto u : d)
                FOR(v, k)
                    if (a[v][u])
                        msk &= ~(1<<v);
            sum += f[msk];
            if (sum > maxSum) {
                maxSum = sum;
                ways = cnt[msk];
            } else if (sum==maxSum)
                ways += cnt[msk];
        }
    }

    cout << maxSum << ' ' << ways << endl;

    return 0;
}