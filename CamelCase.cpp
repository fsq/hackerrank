#include "stdc++.h"

int main() {
    string s;
    cin >> s;
    int n = count_if(ALL(s), [](char c){ return isupper(c); });
    cout << n+1 << endl;
    return 0;
}