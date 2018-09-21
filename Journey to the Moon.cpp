#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.

vector<int> fa, sz;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

long journeyToMoon(int n, vector<vector<int>> a) {
    fa.resize(n), sz.resize(n);
    iota(fa.begin(), fa.end(), 0);
    fill(sz.begin(), sz.end(), 1);
    
    for (auto& pr : a) {
        int fx=find(pr[0]), fy=find(pr[1]);
        if (fx!=fy) {
            fa[fx] = fy;
            sz[fy] += sz[fx];
        }
    }
    
    vector<int> g;
    for (int i=0; i<n; ++i)
        if (fa[i]==i) 
            g.push_back(sz[i]);

    long ans = 0, sum = g.back();
    for (auto it=g.rbegin()+1; it!=g.rend(); ++it) {
        ans += *it * sum;
        sum += *it;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
