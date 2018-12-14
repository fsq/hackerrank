#include "stdc++.h"

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        if (next_permutation(ALL(s)))
            cout << s << '\n';
        else 
            cout << "no answer" << '\n';
    }
    return 0;
}