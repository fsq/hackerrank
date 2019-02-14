#include "stdc++.h"

int main() {
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		VI a(n);
		FOR(i, n) cin >> a[i];
		unordered_map<int, int> pos;
		FOR(i, n) {
			if (pos.count(m - a[i])) {
				cout << pos[m-a[i]]+1 <<' '<< i+1 << endl;
				break;
			}
			if (!pos.count(a[i]))
				pos[a[i]] = i;
		}
	}
	return 0;
}