#include "stdc++.h"

int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    VI f(n+1);
    REP(i, 0, n)
      f[i] = !((i<3 || f[i-3]) && 
               (i<2 || f[i-2]) && 
               (i<5 || f[i-5]));
    cout << (f[n] ? "First" : "Second") << endl;
  }
  return 0;
}