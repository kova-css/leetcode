#include <bits/stdc++.h>

using namespace std;

bool existsEven(unordered_map<char, int> map) {
    for (int i = 'a'; i < 'z'; i++) {
        if (map[i] >= 2) {
            return true;
        }
    }
    return false;
}

bool buddyStrings(string s, string goal) {
    unordered_map<char, int> map1, map2;
    int diffs = 0;

    if (s.length() != goal.length()) {
        return false;
    }

    for (int i = 0; i < s.length(); ++i) {
        map1[s[i]]++;
        map2[goal[i]]++;
        if (s[i] != goal[i]) {
            diffs++;
        }
    }

    if (map1 != map2 || diffs > 2 || (s == goal && !existsEven(map1))) {
        return false;
    }
    
    return true;
}

int main() {
    string norm = "abab", goal = "abab";

    cout << buddyStrings(norm, goal) << endl;

    return 0;
}