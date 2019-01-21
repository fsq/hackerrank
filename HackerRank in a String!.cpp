#include "stdc++.h"

int main() {
    int t;
    cin >> t;
    string s, target = "hackerrank";
    while (t--) {
        cin >> s;
        int j = 0;
        FORI(i, s)
            if (s[i]==target[j] && ++j==target.size())
                break;
        cout << (j==target.size() ? "YES" : "NO") << endl;
    }
    return 0;
}