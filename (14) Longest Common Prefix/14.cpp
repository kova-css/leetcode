#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs.front();
    if (prefix == "") {
        return "";
    }
    for (int i = 1; i < strs.size(); i++) {
        if (strs[i] == prefix) {
            continue;
        }
        int iter = 0;
        string nextWord = "";
        while (strs[i][iter] == prefix[iter]) {
            nextWord += strs[i][iter];
            iter++;
        }
        if (nextWord == "") {
            return "";
        }
        prefix = nextWord;
    }
    return prefix;
}

int main() {
    vector<string> words = {"flower","flower","flower","flower"};
    cout << longestCommonPrefix(words) << endl;
    return 0;
}