#include "stdc++.h"

int main() {
    string s;
    cin >> s;

    string::iterator it = s.begin();
    while ((it=adjacent_find(ALL(s))) != end(s)) {
        s.erase(next(it));
        s.erase(it);
    }
    cout << s << endl;
    return 0;
}