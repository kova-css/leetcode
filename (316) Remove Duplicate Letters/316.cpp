#include <bits/stdc++.h>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> freq(26, 0);
    vector<bool> inStack(26, false);
    stack<char> result;

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (char c : s) {
        freq[c - 'a']--;

        if (inStack[c - 'a']) {
            continue;
        }

        while (!result.empty() && c < result.top() && freq[result.top() - 'a'] > 0) {
            inStack[result.top() - 'a'] = false;
            result.pop();
        }
        result.push(c);
        inStack[c - 'a'] = true;

    }

    string resultStr = "";
    while (!result.empty()) {
        resultStr = result.top() + resultStr;
        result.pop();
    }
    
    return resultStr;
}

int main() {

    string s = "cbacdcbc";

    cout << removeDuplicateLetters(s) << endl;

    return 0;
}