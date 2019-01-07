#include "stdc++.h"

int main() {
    ios::sync_with_stdio(false);

    string s;
    LL a = 0;
    int k;
    cin >> s >> k;

    for (auto c : s) a += c - '0';
    a *= k;

    while (a>=10) {
        int s = 0;
        while (a) {
            s += a % 10;
            a /= 10;
        }
        a = s;
    }
    cout << a << endl;


    return 0;
}