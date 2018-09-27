#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int,int>>> e(n+1);
    for (auto& p : edges) {
        e[p[0]].emplace_back(p[1], p[2]);
        e[p[1]].emplace_back(p[0], p[2]);
    }
    
    vector<int> d(n+1, INT_MAX);
    vector<int> vis(n+1);
    priority_queue<pair<int,int>> q;
    q.push({0, start});
    d[start] = 0;
    int ans = 0;
    while (!q.empty()) {
        while (!q.empty() && vis[q.top().second]) q.pop();
        if (!q.empty()) {
            int x, l;
            tie(l, x) = q.top();
            q.pop();
            vis[x] = true, ans += -l;
            
            for (auto& p : e[x])
                if (p.second < d[p.first]) {
                    d[p.first] = p.second;
                    q.push({-p.second, p.first});
                }
        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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

