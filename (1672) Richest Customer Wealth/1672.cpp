#include <bits/stdc++.h>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int max = INT_MIN;
    int pocketsize = accounts[0].size();
    int accountsNum = accounts.size();
    for (int i = 0; i < accountsNum; i++) {
        int temp = 0;
        for (int j = 0; j < pocketsize; j++) {
            temp += accounts[i][j];
        }
        if (temp > max){
            max = temp;
        }
    }
    return max;
}

int main() {


    return 0;
}