#include "stdc++.h"

const int N = 5007;
const int M = 1e9 + 7;
int n, k, l;
int tag[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> l;

    for (int x,i=0; i<k; ++i) {
        cin >> x;
        tag[x] = -1;
    }    

    for (int x,i=0; i<l; ++i) {
        cin >> x;
        if (tag[x]==-1) {
            cout << 0 << endl;
            return 0;
        }
        tag[x] = 1;
    }

    REP(i, 1, n-1) 
        if (tag[i] && tag[i] == tag[i+1]) {
            cout << 0 << endl;
            return 0;
        }

    VVLL f(n+1, VLL(n+1));
    VLL s(n+1);
    f[1][1] = s[1] = 1;
    REP(i, 2, n) {
        if (!tag[i] && !tag[i-1]) {
            REP(j, 1, i) 
                f[i][j] = s[i-1];
        } else if (tag[i-1]==1 || tag[i]==-1) {
            REP(j, 1, i)
                f[i][j] = (s[i-1] - s[j-1] + M) % M;
        } else {
            REP(j, 1, i)
                f[i][j] = s[j-1];
        }
        REP(j, 1, i) s[j] = (s[j-1] + f[i][j]) % M;
    }

    cout << s[n] << endl;
    return 0;
}