#include "stdc++.h"

const int M = 1e9 + 7;
const int N = 5007;

int tag[N];
LL C[N][N];
int n;
VVI a;
bool boom = false;

void init() {
  ios::sync_with_stdio(false);
  MEMSET0(tag);
}

void read() {
  cin >> n;
  int k, l;
  cin >> k >> l;
  for (int x,i=0; i<k; ++i) {
    cin >> x;
    tag[x] = -1;
  }

  for (int x,i=0; i<l; ++i) {
    cin >> x;
    if (tag[x]==-1) {
      boom = true;
      break;
    }
    tag[x] = 1;
  }

  REP(i, 1, n-1)
    if (tag[i] && tag[i]==tag[i+1]) {
      boom = true;
      return;
    }

  for (int j=1,i=1; i<=n; i=j) 
    if (tag[i] || tag[i+1]) {
      VI seg{0, 1};
      j = i + 1;
      while (j<=n) {
        if (tag[j])
          seg.PB(tag[j]);
        else if (tag[j-1])
          seg.PB(-tag[j-1]);
        else
          break;
        ++j;
      }
      a.PB(move(seg));
    } else {
      j = i + 1;
    }
}

int dp(CVI& a) {
  int n = SZ(a) - 1;
  VVLL f(n+1, VLL(n+1));
  VLL s(n+1);
  f[1][1] = s[1] = 1;
  REP(i, 2, n) {
    if (a[i] == 1)
      REP(j, 1, i) 
        f[i][j] = s[j-1];
    else 
      REP(j, 1, i)
        f[i][j] = (s[i-1] - s[j-1] + M) % M;
    REP(j, 1, i) 
      s[j] = (s[j-1] + f[i][j]) % M;
  }
  return s[n];
}

void comb() {
  C[1][1] = 1;
  REP(i, 2, n) {
    C[i][1] = i;
    REP(j, 2, i)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
  }
}

int main() {
  init();

  read();

  comb();

  if (boom) {
    cout << 0 << endl;
  } else {
    LL ans = 1;
    FOREACH(&seg, a) {
      ans = (ans * dp(seg)) % M;
      ans = (ans * C[n][SZ(seg)-1]) % M;
      n -= SZ(seg) - 1;
    }

    REP(x, 2, n)
      ans = (ans * x) % M;

    cout << ans << endl;
  }
  return 0;
}