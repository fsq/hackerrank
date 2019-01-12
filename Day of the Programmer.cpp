#include "stdc++.h"

bool isLeap(int x) {
    if (x<=1917)
        return x % 4 == 0;
    else 
        return x%400==0 || (x%4==0 && x%100!=0);
}

int main() {
    VI months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y;
    cin >> y;
    if (y==1918)
        months[2] = 15;
    if (isLeap(y))
        ++months[2];
    int d = 256, i;
    for (i=1; d>months[i]; ++i)
        d -= months[i];
    if (y==1918 && i==2)
        d += 13;
    cout << (d<10 ? "0" : "") << d << '.';
    cout << (i<10 ? "0" : "") << i << '.';
    cout << y << endl;
    return 0;
}