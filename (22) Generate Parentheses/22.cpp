#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<string>& result, string& current, int open, int close, int n) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    if (open < n) {
        current.push_back('(');
        backtrack(result, current, open + 1, close, n);
        current.pop_back();
    }
    
    if (close < open) {
        current.push_back(')');
        backtrack(result, current, open, close + 1, n);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    
    backtrack(result, current, 0, 0, n);
    
    return result;
}


int main() {
    int n = 3;
    for (auto i : generateParenthesis(n)) {
        cout << i << endl;
    }

    return 0;
}