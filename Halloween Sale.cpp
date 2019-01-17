#include "stdc++.h"

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    int x = (p-m)*1.0 / d, ans = 0;

    int s1 = (2*p-x*d) * (x+1) / 2;
    if (s1<=s) {
        s -= s1;
        ans = x + 1 + s/m; 
    } else if (s<p) 
        ans = 0;
    else 
        ans = (sqrt(pow(2*p-d,2)+4*d*(2*p-2*s))+d-2*p) / (-2.0*d) + 1;
    
    cout << ans << endl;

    return 0;
}