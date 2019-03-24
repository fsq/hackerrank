#include "stdc++.h"

int main() {
  int n, s = 0, x;
  cin >> n;
  FOR(i, n) {
    cin >> x;
    s ^= x;
  }
  cout << s << endl;
  return 0;
}