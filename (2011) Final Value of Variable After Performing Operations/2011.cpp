#include <bits/stdc++.h>

using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int fin = 0;
    for (int i = 0; i < operations.size(); i++) {
        fin += operations[i][1] == '+' ? 1 : -1;
    }
    return fin;
}

int main() {



    return 0;
}