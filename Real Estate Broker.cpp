#include <stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the realEstateBroker function below.
 */

VVI e;
VI d, M;
int n;
const int INF = 0x3f3f3f3f;

bool bfs() {
    FILL(d, INF);
    queue<int> q;
    REP(i, 1, n)
        if (!M[i]) {
            d[i] = 0;
            q.push(i);
        }
    while (q.size()) {
        int u = q.front(); q.pop();
        if (d[u]<d[0]) 
            FOREACH(y, e[u])
                if (d[M[y]]==INF) {
                    d[M[y]] = d[u] + 1;
                    q.push(M[y]);
                }
    }

    return d[0] != INF;
}

bool dfs(int u) {
    if (!u) return true;
    int du = d[u];
    d[u] = INF;
    FOREACH(v, e[u])
        if (d[M[v]]==du+1 && dfs(M[v])) {
            M[v] = u;
            M[u] = v;
            return true;
        }
    return false;
}

int realEstateBroker(vector<vector<int>> c, vector<vector<int>> h) {
    n = c.size();
    e.resize(n+1);
    d.resize(n+1);
    M.resize(n+h.size()+1);

    FORI(i, c)
        FORI(j, h) 
            if (h[j][0]>c[i][0] && h[j][1]<=c[i][1]) 
                e[i+1].PB(n+1+j);

    int ans = 0;
    while (bfs())
        REP(i, 1, n)
            ans += !M[i] && dfs(i);

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

    vector<vector<int>> clients(n);
    for (int clients_row_itr = 0; clients_row_itr < n; clients_row_itr++) {
        clients[clients_row_itr].resize(2);

        for (int clients_column_itr = 0; clients_column_itr < 2; clients_column_itr++) {
            cin >> clients[clients_row_itr][clients_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> houses(m);
    for (int houses_row_itr = 0; houses_row_itr < m; houses_row_itr++) {
        houses[houses_row_itr].resize(2);

        for (int houses_column_itr = 0; houses_column_itr < 2; houses_column_itr++) {
            cin >> houses[houses_row_itr][houses_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = realEstateBroker(clients, houses);

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

