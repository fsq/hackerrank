#include "stdc++.h"

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;

    FOREACH(&c, s) 
        if (isupper(c))
            c = (c-'A'+k) % 26 + 'A';
        else if (islower(c))
            c = (c-'a'+k) % 26 + 'a';
    cout << s << endl;
    return 0;
}