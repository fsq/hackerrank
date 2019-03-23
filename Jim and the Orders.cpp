#include "stdc++.h"

int main() {
  int n;
  cin >> n;
  vector<PII> a(n);
  FOR(i, n) {
    cin >> a[i].first >> a[i].second;
    a[i].first += a[i].second;
    a[i].second = i + 1;
  }

  sort(ALL(a));
  FORI(i, a) cout << a[i].second << ' ';
  cout << endl;
  return 0;
}