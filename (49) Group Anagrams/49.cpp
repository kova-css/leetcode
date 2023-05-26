#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        groups[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto& pair : groups) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(words);
    return 0;
}