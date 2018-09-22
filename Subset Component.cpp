#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findConnectedComponents function below.
vector<int> fa;

int find(int x, vector<int>& fa) {
    return fa[x]==x ? x : fa[x]=find(fa[x], fa);
}

void dfs(const vector<long>& d, vector<int>& fa, int& ans, int i, int cc) {
    ans += cc;
    
    for (int j=i; j<d.size(); ++j) {
        vector<int> ft = fa;
        vector<int> g;
        int ct = cc;
        for (int k=0; k<64; ++k)
            if ((d[j]>>k) & 1)
                g.push_back(k);
        for (int k=0; k+1<g.size(); ++k) {
            int fx=find(g[k], ft), fy=find(g[k+1], ft);
            if (fx != fy) {
                --ct;
                ft[fx] = fy;
            }
        }
        dfs(d, ft, ans, j+1, ct);
    }    
}

int findConnectedComponents(vector<long> d) {
    int n = d.size();
    int ans = 0;
    fa.resize(64);
    iota(fa.begin(), fa.end(), 0);
    dfs(d, fa, ans, 0, 64);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int d_count;
    cin >> d_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string d_temp_temp;
    getline(cin, d_temp_temp);

    vector<string> d_temp = split_string(d_temp_temp);

    vector<long> d(d_count);

    for (int i = 0; i < d_count; i++) {
        long d_item = stol(d_temp[i]);

        d[i] = d_item;
    }

    int components = findConnectedComponents(d);

    fout << components << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
