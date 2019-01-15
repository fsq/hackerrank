#include "stdc++.h"

int main() {
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    if (y1>y2)
        cout << "10000\n";
    else if (y1<y2 || m1<m2 || (m1==m2 && d1<=d2))
        cout << "0\n";
    else if (m1>m2) 
        cout << 500*(m1-m2) << endl;
    else 
        cout << 15*(d1-d2) << endl;
    return 0;
}