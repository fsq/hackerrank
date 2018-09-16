#include <bits/stdc++.h>
#include <thread>

using namespace std;

// Complete the diagonalDifference function below.

void calc(const vector<vector<int>>& a, int& ans, int dir) {
    ans = 0;
    if (dir==0)
        for (int i=0; i<a.size(); ++i)
            ans += a[i][i];
    else
        for (int i=0; i<a.size(); ++i)
            ans += a[i][a.size()-i-1];
}

int diagonalDifference(vector<vector<int>> arr) {
    int d1, d2;
    thread t1(calc, ref(arr), ref(d1), 0);
    thread t2(calc, ref(arr), ref(d2), 1);
    t1.join(), t2.join();
    return abs(d1 - d2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
