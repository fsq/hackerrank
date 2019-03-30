#include "stdc++.h"

int main() {
  int n, g, x;
  cin >> g;
  while (g--) {
    cin >> n;
    int s = 0;
    while (n--) {
      cin >> x;
      s ^= x;
    }  
    cout << (s ? "First" : "Second") << endl;
  }
  return 0;
}