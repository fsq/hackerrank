#include "stdc++.h"

int main() {
  int t;
  cin >> t;
  LL b, n, k;
  while (t--) {
    cin >> n >> k >> b;
    VLL a(b);
    iota(ALL(a), 1);
    if (LL sum = (1 + b) * b / 2; sum > n)
      cout << -1 << endl;
    else {
      LL res = n - sum;
      LL add = res / b;
      FOREACH(&x, a) x += add;
      res -= add * b;
      for (int i=b-1; res>0; --i, --res)
        ++a[i];
      if (a.back() > k)
        cout << -1 << endl;
      else {
        FOREACH(x, a) cout << x << ' ';
        cout << endl;
      }
    }
  }
  return 0;
}