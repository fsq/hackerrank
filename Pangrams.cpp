#include "stdc++.h"

int main() {
    string s;
    getline(cin, s);
    VI cnt(26);

    FOREACH(c, s) 
        if (isalpha(c))
            ++cnt[tolower(c)-'a'];

    cout << (all_of(ALL(cnt), [](int x){ return x>0; }) ? 
             "pangram" : "not pangram") << endl;
    return 0;
}