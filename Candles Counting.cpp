#include "stdc++.h"

int n, k;
const int M = 1e9 + 7;
const int N = 5e4;
int s[130][N + 3];
int h[N + 3], c[N + 3];

void init() {
  ios::sync_with_stdio(false);
  MEMSET0(s);
  cin >> n >> k;
  REP(i, 1, n) {
    cin >> h[i] >> c[i];
    --c[i];
  }
}

inline int lowbit(int x) {
  return x & (-x);
}

int sum(int s[], int i) {
  int ans = 0;
  for (; i; i-=lowbit(i))
    ans = (ans + s[i]) % M;
  return ans;
}

void add(int s[], int i, int x) {
  if (!x) return;
  for (; i<=N; i+=lowbit(i))
    s[i] = (s[i] + x) % M;
}

int main() {
  init();
  REP(i, 1, n) {
    add(s[1<<c[i]], h[i], 1);
    FOR(cl, 1<<k) 
      if ((cl>>c[i]) & 1) {
        add(s[cl], h[i], sum(s[cl], h[i]-1));
        add(s[cl], h[i], sum(s[cl ^ (1<<c[i])], h[i]-1));
      }
  }

  cout << sum(s[(1<<k)-1], N) << endl;
  return 0;
}