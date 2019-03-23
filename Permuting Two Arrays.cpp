#include "stdc++.h"

int main() {
  int q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    VI a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b), greater<int>());
    bool ok = true;
    FOR(i, n) 
      if (a[i] + b[i] < k) {
        ok = false;
        break;
      }
    cout << (ok ? "YES" : "NO") << endl;
  }   
  return 0;
}