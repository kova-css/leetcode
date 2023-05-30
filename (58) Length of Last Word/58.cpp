#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s) {
    int it = s.length() - 1;
    while (s[it] == ' ') it--;
    int len = 0;
    while (s[it] && s[it] != ' ') {
        len++;
        if (it != 0) {
            it--;
        }else {
            return len;
        }
    }
    return len;
}


int main() {
    string s = "a";
    cout << lengthOfLastWord(s) << endl;

    return 0;
}