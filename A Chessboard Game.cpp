#include "stdc++.h"

VI dx = {-2, -2, 1, -1};
VI dy = {1, -1, -2, -2};

bool win(VVI& a, int x, int y) {
  if (x<1 || y<1 || x>15 || y>15) return true;
  if (a[x][y]) return a[x][y] == 1;
  for (int dir=0; dir<4; ++dir)
    if (!win(a, x+dx[dir], y+dy[dir])) {
      a[x][y] = 1;
      return true;
    }
  a[x][y] = -1;
  return false;
}

int main() {
  int t, x, y;
  cin >> t;
  while (t--) {
    VVI a(16, VI(16));
    cin >> x >> y;
    cout << (win(a,x,y) ? "First" : "Second") << endl;
  }
  return 0;
} 