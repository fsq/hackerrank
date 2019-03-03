#include "stdc++.h"

int main() {
	int n, m;

	cin >> n;
	VI a(n);
	FOR(i, n) cin >> a[i];

	cin >> m;
	VI b(m);
	FOR(i, m) cin >> b[i];
	

	auto range = minmax_element(ALL(b));
	int mn=*range.first, mx=*range.second;

	VI ba(mx-mn+1), bb=ba;
	FOREACH(x, b) ++bb[x-mn];
	FOREACH(x, a) ++ba[x-mn];

	FOR(i, SZ(bb))
		if (bb[i]-ba[i]) 
			cout << i+mn << ' ';

	return 0;
}