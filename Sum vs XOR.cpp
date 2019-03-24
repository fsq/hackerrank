#include "stdc++.h"

int main() {
  LL n;
  cin >> n;
  int b = 0;
  while (n) {
    b += !(n & 1);
    n >>= 1;
  }
  cout << (1ll<<b) << endl;
  return 0;
}