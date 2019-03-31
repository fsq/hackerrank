#include "stdc++.h"

int main() {
  int n, g, x;
  cin >> g;
  while (g--) {
    cin >> n;
    int s = 0, mx = 0;
    while (n--) {
      cin >> x;
      mx = max(mx, x);
      s ^= x;
    }  
    if (mx <= 1)
      cout << ((s&1) ? "Second" : "First") << endl;
    else
      cout << (s ? "First" : "Second") << endl;
  }
  return 0;
}