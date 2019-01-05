#include "stdc++.h"

struct city {
    int x;
    LL p;
    city(int _x): x(_x) {}
    city(int _x, LL _p): x(_x), p(_p) {}
    city() = default;
};
struct cloud {
    int l, r, x, radius;
};
int n, m;
LL ans;

vector<city> removeCity(const vector<city>& a, const vector<cloud>& c) {
    vector<city> s;
    map<int, LL> m;
    FOREACH(&cl, c) {
        ++m[cl.l];
        --m[cl.r+1];
    }
    for (auto it=next(m.begin()); it!=m.end(); ++it)
        it->second += prev(it)->second;
    FOREACH(&ct, a) {
        auto it = m.upper_bound(ct.x);
        if (it==m.begin() || prev(it)->second<2) {
            s.PB(ct);
            if (it==m.begin() || prev(it)->second==0) ans += ct.p;
        }
    }
    return s;
}


int main() {
    cin >> n;
    vector<city> a(n);
    FOR(i, n) cin >> a[i].p;
    FOR(i, n) cin >> a[i].x;

    cin >> m;
    vector<cloud> c(m);
    FOR(i, m) cin >> c[i].x;
    FOR(i, m) {
        cin >> c[i].radius;
        c[i].l = c[i].x - c[i].radius;
        c[i].r = c[i].x + c[i].radius;
    }
    ans = 0;
    a = removeCity(a, c);
    sort(ALL(a), [](const city& a, const city& b) {
        return a.x < b.x;
    }); 
    n = a.size();

    if (n==0) {
        cout << 0 << endl;
        return 0;
    }

    VLL s(n);
    s[0] = a[0].p;
    REP(i, 1, n-1) s[i] = s[i-1] + a[i].p;

    LL maxinc = 0;
    FOREACH(&cl, c) {
        int itl = lower_bound(ALL(a), city(cl.l), [](const city& a, const city& b){
            return a.x < b.x;
        }) - a.begin();
        int itr = upper_bound(ALL(a), city(cl.r), [](const city& a, const city& b){
            return a.x < b.x;
        }) - a.begin() - 1;
        if (itl <= itr) {
            LL increase = s[itr] - (itl==0 ? 0 : s[itl-1]);
            maxinc = max(maxinc, increase);        
        }
    }

    cout << ans + maxinc << endl;

    return 0;
}