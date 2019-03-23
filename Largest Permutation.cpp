#include "stdc++.h"

int main() {
    int n, k;
    cin >> n >> k;

    VI a(n+1), pos(n+1);
    REP(i, 1, n) {
      cin >> a[i];
      pos[a[i]] = i;
    }

    for (int i=1; k && i<=n; ++i) {
      int target = n - i + 1;
      if (pos[target] != i) {
        --k;
        pos[a[i]] = pos[target];
        swap(a[i], a[pos[target]]);
        pos[target] = i;
      }
    }
    REP(i, 1, n) cout << a[i] << ' ' ;
    cout << endl;
    return 0;
}