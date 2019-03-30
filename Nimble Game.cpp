#include "stdc++.h"

int main() {
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    int sum = 0;
    cin >> x;
    REP(i, 1, n-1) {
      cin >> x;
      if (x&1) sum ^= i;
    }
    
    cout << (sum ? "First" : "Second") << endl;
  }
  return 0;
}