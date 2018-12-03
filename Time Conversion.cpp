#include "stdc++.h"

int main() {
    int h; 
    string s;
    cin >> h >> s;

    string t = s.substr(s.size()-2);
    s.pop_back(); s.pop_back();

    if (t=="PM" && h<12)
        h += 12;
    if (t=="AM" && h==12)
        h = 0;

    cout << (h<10 ? "0" : "") << h << s << endl;

    return 0;
}