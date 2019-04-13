#include "stdc++.h"

const int N = 10;

vector<string> a(N), w;
vector<vector<PII>> e(N+1, vector<PII>(N+1, {-1,-1})),
                    m(N+1, vector<PII>(N+1));
VI slot = {0};
VVI pos(N+1);
VI dx = {0, 1}, dy = {1, 0};

void mark() {
  int ind = 1;
  FOR(i, N) {
    for (int j=0; j<N; )
      if (a[i][j]=='-' && j+1<N && a[i][j+1]=='-') {
        int len = 0;
        pos[ind] = {i, j, 0};
        while (j<N && a[i][j]=='-') {
          m[i][j] = {ind, len};
          ++len, 
          ++j;
        }
        ++ind;
        slot.PB(len);
      } else 
        ++j;
  }
  FOR(i, N) 
    for (int j=0; j<N; )
      if (a[j][i]=='-' && ((j+1<N && a[j+1][i]=='-') || !m[j][i].F)) {
        int len = 0;
        pos[ind] = {j, i, 1};
        while (j<N && a[j][i]=='-') {
          if (m[j][i].F) 
            e[ind][m[j][i].F] = {len, m[j][i].S};
          ++len;
          ++j;
        }
        ++ind;
        slot.PB(len);  
      } else
        ++j;
}

bool ok(VI& ans, int pos, int ind) {
  if (SZ(w[ind]) != slot[pos]) return false;
  REP(i, 1, pos-1)
    if (e[pos][i].F != -1) 
      return w[ind][e[pos][i].F] == w[ans[i]][e[pos][i].S];
  return true;
}

bool dfs(VI& ans, VI& vis, int i) {
  if (i == SZ(slot))
    return true;
  else 
    FOR(j, SZ(w))
      if (!vis[j] && ok(ans, i, j)) {
        ans.PB(j);
        vis[j] = true;
        if (dfs(ans, vis, i+1)) return true;
        ans.pop_back();
        vis[j] = false;
      }
  return false;
}

int main() {
  FOR(i, N) cin >> a[i];
  string words;
  cin >> words;
  istringstream sin(words);
  for (string s; getline(sin, s, ';'); w.PB(s));

  mark();
  VI ans = {-1};

  VI vis(SZ(w));
  dfs(ans, vis, 1);

  REP(i, 1, SZ(w)) {
    int x = pos[i][0], y = pos[i][1], dir = pos[i][2];
    FOR(l, SZ(w[ans[i]])) {
      a[x][y] = w[ans[i]][l];
      x += dx[dir], y += dy[dir];
    }
  }

  FOREACH(&row, a)
    cout << row << '\n';

  return 0;
}