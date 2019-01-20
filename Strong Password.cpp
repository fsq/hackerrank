#include "stdc++.h"
#define NONE string::npos

string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";

int main() {
    int n;
    string s;
    cin >> n >> s;
    bool hasNumbers=false, hasLower=false, hasUpper=false, hasSpecial=false;
    FOREACH(c, s)
        if (numbers.find(c)!=NONE)
            hasNumbers = true;
        else if (lower_case.find(c)!=NONE)
            hasLower = true;
        else if (upper_case.find(c)!=NONE)
            hasUpper = true;
        else if (special_characters.find(c)!=NONE)
            hasSpecial = true;
    int ans = max(6-SZ(s), 
                  !hasNumbers + !hasLower + !hasUpper + !hasSpecial - max(0, 6-SZ(s)));
    cout << ans << endl;
    return 0;
}