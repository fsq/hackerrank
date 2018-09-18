#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.

template <class S, class T>
class syncMap {
    unordered_map<S, T> map;
    mutex m;
    int freq = 0;
public:
    syncMap() { }
    
    void add(S x) {
        lock_guard<mutex> lk(m);
        freq = max(freq, ++map[x]);
    }
        
    int getMajority() {
        lock_guard<mutex> lk(m);
        int ans = INT_MAX;
        for (auto& kv : map)
            if (kv.second==freq && kv.first<ans)
                ans = kv.first;
        return ans;
    }
};

void add(vector<int>::iterator beg, vector<int>::iterator end, syncMap<int, int>& map) {
    while (beg!=end) {
        map.add(*beg);
        ++beg;
    }
}

int migratoryBirds(vector<int> arr) {
    syncMap<int, int> map;
    int n = arr.size();
    thread t1(add, arr.begin(), arr.begin()+n/2, ref(map));
    add(arr.begin()+n/2, arr.end(), ref(map));
    t1.join();
    
    return map.getMajority();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

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

