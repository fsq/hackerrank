#include "stdc++.h"

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		VI a(n);
		FOR(i, n) cin >> a[i];
		int sum = accumulate(ALL(a), 0), cur = 0;

		bool found = false;
		FOR(i, n) {
			if (cur==sum-cur-a[i]) {
				found = true;
				break;
			}
			cur += a[i];
		}
		cout << (found ? "YES" : "NO") << endl;
	}
	return 0;
}