#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


// Complete the longestChain function below.
int longestChain(vector<string> words) {
    unordered_map<string, int> f;
    for (auto& s : words) f[s] = 1;
    
    sort(words.begin(), words.end(), [](const string& s, const string& t) {
        return s.size() < t.size();
    });
    
    int i = 0, ans = 0;
    while (i<words.size() && words[i].size()==1) ++i;
    for (; i<words.size(); ++i) {
        for (int j=0; j<words[i].size(); ++j) {
            string s = words[i].substr(0, j) + words[i].substr(j+1);
            if (f.count(s)) f[words[i]] = max(f[words[i]], f[s]+1);
        }
        
        ans = max(ans, f[words[i]]);
    }
    return ans;

}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string words_count_temp;
    getline(cin, words_count_temp);

    int words_count = stoi(ltrim(rtrim(words_count_temp)));

    vector<string> words(words_count);

    for (int i = 0; i < words_count; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    int res = longestChain(words);

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