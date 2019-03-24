#include "stdc++.h"

int l, r;

int main() {
  cin >> l >> r;
  l ^= r;
  int s = 1;
  while (l) {
    s <<= 1;
    l >>= 1;
  }
  cout << (s-1) << endl;
  return 0;
}