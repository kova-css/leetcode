#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s) {
    int maxDepth = 0, curDepth = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            curDepth++;
            if (curDepth > maxDepth) {
                maxDepth = curDepth;
            }
        }else if (s[i] == ')') {
            curDepth--;
        }
    }
    return maxDepth;
}

int main() {


    return 0;
}