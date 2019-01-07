#include "stdc++.h"

int ans = 0;
int x, n;

void dfs(int x, int i) {
    if (x==0)
        ++ans;
    else if (pow(i, n)<=x) {
        dfs(x-pow(i, n), i+1);
        dfs(x, i+1);
    }
}

int main() {
    cin >> x >> n;

    dfs(x, 1);
    cout << ans << endl;

    return 0;
}