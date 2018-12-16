#include "stdc++.h"

int n, m, t;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    
    vector<string> a(n);
    FOR(i, n) cin >> a[i];

    if (t==1) 
        FOR(i, n) {
            cout << a[i];
            cout << '\n';
        }
    else if (!(t & 1)) 
        FOR(i, n) 
            cout << string(m, 'O') << '\n';
    else {
        bool flip = ! ((t+1)/2 & 1);
        vector<string> b = a;
        FOR(i, n) FOR(j, m)
            if (a[i][j]=='O')
                FOR(dir, 4) {
                    int tx=i+dx[dir], ty=j+dy[dir];
                    if (tx>=0 && tx<n && ty>=0 && ty<m)
                        b[tx][ty] = 'O';
                }
        if (flip) {
            FOR(i, n) {
                FOR(j, m)
                    cout << (b[i][j]=='O' ? '.' : 'O');
                cout << '\n';
            }
        } else {
            a = b;
            FOR(i, n) FOR(j, m)
                if (b[i][j]=='.')
                    FOR(dir, 4) {
                        int tx=i+dx[dir], ty=j+dy[dir];
                        if (tx>=0 && tx<n && ty>=0 && ty<m) 
                            a[tx][ty] = '.';
                    }
            FOR(i, n) cout << a[i] << '\n';
        }
    }
    

    return 0;
}