#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


// Complete the friendCircles function below.

int find(vector<int>& fa, int x) {
    return fa[x]==x ? x : fa[x]=find(fa, fa[x]);
}

int friendCircles(vector<string> a) {
    int n = a.size();
    vector<int> fa(n);
    iota(fa.begin(), fa.end(), 0);
    
    int cc = n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (a[i][j]=='Y') {
                int fx=find(fa, i), fy=find(fa, j);
                if (fx != fy) {
                    fa[fx] = fy;
                    --cc;
                }
            }
    return cc;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string friends_count_temp;
    getline(cin, friends_count_temp);

    int friends_count = stoi(ltrim(rtrim(friends_count_temp)));

    vector<string> friends(friends_count);

    for (int i = 0; i < friends_count; i++) {
        string friends_item;
        getline(cin, friends_item);

        friends[i] = friends_item;
    }

    int res = friendCircles(friends);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}