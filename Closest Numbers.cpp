#include "stdc++.h"

int main() {
    int n;
    cin >> n;
    VI a(n);
    FORI(i, a) cin >> a[i];
    sort(ALL(a));
    
    vector<int> ans;
    int gap = INT_MAX;
    for (int i=0; i+1<n; ++i)
        if (a[i+1]-a[i]==gap)
            ans.PB(i);
        else if (a[i+1]-a[i]<gap) {
            gap = a[i+1] - a[i];
            ans = {i};
        }
    FOREACH(i, ans) cout << a[i] << ' ' << a[i+1] << ' ';
    cout << endl;
    return 0;
}