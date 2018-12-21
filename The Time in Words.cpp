#include "stdc++.h"

int main() {
    vector<string> s = {"zero", "one", "two", "three", "four", "five", "six",
                        "seven", "eight", "nine", "ten", "eleven",
                        "twelve", "thirteen", "fourteen", "", "sixteen",
                        "seventeen", "eighteen", "nineteen", "twenty"};
    REP(i, 1, 9) s.PB("twenty "+s[i]);
    s[15] = "quarter";
    s.PB("half");

    int h, m;
    cin >> h >> m;
    if (m==0)
        cout << s[h] << " o' clock\n";
    else if (m<=30) 
        cout << s[m] << (m==15 || m==30 ? "" : (m==1 ? " minute" : " minutes"))
             << " past " << s[h] << '\n';
    else
        cout << s[60-m] << (m==45 ? "" : (m==1 ? " minute" : " minutes"))
             << " to " << s[h+1] << '\n';
    return 0;
}