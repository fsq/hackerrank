#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.

int find(vector<int>& fa, int x) {
    return fa[x]==x ? x : fa[x]=find(fa, fa[x]);
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    int cc = n;
    vector<int> fa(n+1);
    iota(fa.begin(), fa.end(), 0);
    
    for (auto& rd : cities) {
        int fx=find(fa, rd[0]), fy=find(fa, rd[1]);
        if (fx != fy) {
            fa[fx] = fy;
            --cc;
        }
    }
    return min((long)c_lib*cc + (long)(n-cc)*c_road, (long)c_lib*n);
}

int main()
{
    ofstream fout("output.txt");

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

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
