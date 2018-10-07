#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the evenForest function below.
vector<vector<int>> e;
vector<int> sz, vis;

int getSize(int x) {
    if (!x) return 0;
    sz[x] = 1;
    for (auto y : e[x])
        if (!sz[y]) 
            sz[x] += getSize(y);
    return sz[x];
}


int f(int x) {
    if (!x) return 0;
    vis[x] = true;
    int cut = 0;
    for (auto y : e[x])
        if (!vis[y])
            cut += f(y) + !(sz[y] & 1);
    return cut;
}

#define FOR(i, x) for (int i=0; i<x; ++i)
#define PB push_back
int evenForest(int n, int m, vector<int> from, vector<int> to) {
    e.resize(n+1);
    FOR(i, m) {
        e[from[i]].PB(to[i]);
        e[to[i]].PB(from[i]);
    }
    sz.resize(n+1), vis = sz;
    getSize(1);
    return f(1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
