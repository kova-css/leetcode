#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.length(); i++) {
        if (haystack[i] == needle[0]) {
            bool matches = true;
            int pos = i;
            i++;
            for (int j = 1 ; j < needle.length(); j++) {
                if (haystack[i] != needle[j]) {
                    matches = false;
                    break;
                }
                i++;
            }
            if (matches) {
                return pos;
            }else {
                i = pos;
            }
        }
    }
    return -1;
}

int main() {
    string haystack = "mississippi", needle = "pi";
    cout << strStr(haystack, needle) << endl;

    return 0;
}