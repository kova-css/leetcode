#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> fin;
    vector<int> row, rowNxt;
    if (numRows > 0) {
        row.push_back(1);
        fin.push_back(row);
    }else {
        return fin;
    }
    if (numRows > 1) {
        row.push_back(1);
        fin.push_back(row);
    }else {
        return fin;
    }
    for (int i = 3; i < numRows+1; i++) {
        rowNxt.push_back(1);
        for (int j = 0; j < i-2; j++) {
            rowNxt.push_back(row[j]+row[j+1]);
        }
        rowNxt.push_back(1);
        row = rowNxt;
        rowNxt.clear();
        fin.push_back(row);
    }
    return fin;
}

int main() {
    vector<vector<int>> perm = generate(5);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < perm[i].size(); j++) {
            cout << perm[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}