#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
    int scanner = -1;
    for (int i = 0; i < s.length(); i++) {
        bool found = false;
        for (int j = scanner+1; j < t.length(); j++) {
            if (s[i] == t[j]) {
                found = true;
                scanner = j;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    string s, t;
    s = "aaaaaa";
    t = "bbaaaa";
    cout << isSubsequence(s, t) << endl;


    return 0;
}