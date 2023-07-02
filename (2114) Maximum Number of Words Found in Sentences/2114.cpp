#include <bits/stdc++.h>

using namespace std;

int mostWordsFound(vector<string>& sentences) {
    int maxwords = 0;
    for (int i = 0; i < sentences.size(); i++) {
        int temp = 1;
        for (int j = 0; j < sentences[i].length(); j++) {
            if (sentences[i][j] == ' ') {
                temp++;
            }
        }
        if (temp > maxwords) {
            maxwords = temp;
        }
    }
    return maxwords;
}

int main() {


    return 0;
}