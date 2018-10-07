#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
using VI = vector<int>;
using VVI = vector<VI>;
#define PB push_back
VVI e;
VI fa, tag;

void dfs(int x) {
    if (!x) return;

    for (auto y : e[x])
        if (y!=fa[x]) {
            fa[y] = x;
            dfs(y);
        }
}

int get(int x, int k) {
    if (!x) return 0;
    int ans = 0;

    if (tag[x]>=k)
        ++ans;

    for (auto y : e[x])
        if (y!=fa[x]) {
            tag[y] += tag[x];
            ans += get(y, k);
        }
    return ans;
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

string storyOfATree(int n, vector<vector<int>> edges, int k, vector<vector<int>> guesses) {

    e = VVI(n+1);
    for (auto& p : edges) {
        e[p[0]].PB(p[1]);
        e[p[1]].PB(p[0]);
    }
    fa = tag = VI(n+1);

    int root = rand()% n + 1;
    dfs(root);

    for (auto& g : guesses) 
        if (fa[g[1]]==g[0]) { 
            ++tag[root];
            --tag[g[1]];
        } else 
            ++tag[g[0]];

    int ans = get(root, k);

    int g = gcd(ans, n);
    ans /= g, n /= g;
    return to_string(ans) + "/" + to_string(n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> edges(n-1);
        for (int edges_row_itr = 0; edges_row_itr < n-1; edges_row_itr++) {
            edges[edges_row_itr].resize(2);

            for (int edges_column_itr = 0; edges_column_itr < 2; edges_column_itr++) {
                cin >> edges[edges_row_itr][edges_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string gk_temp;
        getline(cin, gk_temp);

        vector<string> gk = split_string(gk_temp);

        int g = stoi(gk[0]);

        int k = stoi(gk[1]);

        vector<vector<int>> guesses(g);
        for (int guesses_row_itr = 0; guesses_row_itr < g; guesses_row_itr++) {
            guesses[guesses_row_itr].resize(2);

            for (int guesses_column_itr = 0; guesses_column_itr < 2; guesses_column_itr++) {
                cin >> guesses[guesses_row_itr][guesses_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = storyOfATree(n, edges, k, guesses);

        fout << result << "\n";
    }

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
