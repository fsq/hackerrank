#include "stdc++.h"

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;  
		cin >> s;
		cout << unordered_set<char>(ALL(s)).size() << endl;
	}
}